#include <iostream>
using namespace std;

class Polynomial
{
  private:
    double* array;
    int exponent;
    int max = 10;
  
  public:
   Polynomial(){
      exponent = 0;
      array = new double[exponent + 1];
      array[0] = 0;
    }
  
  void print() const {
    bool firstNonZero = false;
    for (int i = 0; i < exponent; i++) {
      if (array[exponent - i - 1] != 0) {
        firstNonZero = true;
        cout << array[exponent - i - 1];
        if ((exponent - i - 1) != 0)  {
          cout << "x^" << exponent - i - 1 ;
        }
      }
      if (firstNonZero && (i < (exponent - 1))) {
        cout << " + ";
      }
    }
    if (firstNonZero == false) {
      cout << " xcvb";
    }
  }
  
  Polynomial(double arr[], int exp){
    exponent = exp;
    array = new double[exponent];
    for(int i = 0; i < exp; i++)
      array[i] = arr[i];
  }
  
  Polynomial(double c){
     exponent = 1;
    array = new double[exponent];
    array[0] = c;
  }
  
  void setArray(double arr, int size) {
    if (size >= exponent) {
      cerr << "This polynomnial does not have such a high exponent.";
      exit(0);
    } else {
      array[size] = arr;
    }
  }
  double getArray(const int& size) const {
    if (size >= exponent) {
      cerr << "This polynomnial does not have such a high exponent.";
      exit(0);
    } else {
      return array[size];
    }
  }
  
  double evaluate(double value) const
   {
     double power = 1;
     double result = 0;
     for(int i =0; i <= exponent; i++){
       result += array[i] * power;
       power *= value;
     }
     return result;
   }
  
  Polynomial(const Polynomial& object){
     if (exponent != object.exponent) {
      delete [] array;
      exponent = object.exponent;
      array = new double[exponent];
    }
    for (int i = 0; i < exponent; i++){
      array[i] = object.array[i];
    }
  }
  
  Polynomial operator =(const Polynomial& object) {
    if (exponent != object.exponent) {
      delete [] array;
      exponent = object.exponent;
      array = new double[exponent];
    }
    for (int i = 0; i < exponent; i++) {
      array[i] = object.array[i];
    }
    return *this;
  }
  
  ~Polynomial()
    {
      if (array != NULL)
     {
         delete [] array;
          array = NULL;
              }
          }
  friend const Polynomial operator +(const Polynomial & poly1, const Polynomial & poly2);
  friend const Polynomial  operator -(const Polynomial & poly1, const Polynomial & poly2);
  friend const Polynomial  operator *(const Polynomial & poly1, const Polynomial & poly2);
  friend ostream& operator <<(ostream& output, const Polynomial & poly);
  };
 
const Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2) {
  Polynomial sum;
  if (poly1.exponent >= poly2.exponent) {
    sum.exponent = poly1.exponent;
  } else {
  
    sum.exponent = poly2.exponent;
  }
  delete [] sum.array;
  sum.array = new double[sum.exponent];
  for (int i = 0; i < sum.exponent; i++) {
    sum.array[i] = 0;
    if (i < poly1.exponent) {
      sum.array[i] += poly1.array[i];
    }
    if (i < poly2.exponent) {
      sum.array[i] += poly2.array[i];
    }
  }
  return sum;
}

const Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2) {
  Polynomial difference;
  if (poly1.exponent >= poly2.exponent) {
    difference.exponent = poly1.exponent;
  } else {
    difference.exponent = poly2.exponent;
  }
  delete [] difference.array;
  difference.array = new double[difference.exponent];
  for (int i = 0; i < difference.exponent; i++) {
    difference.array[i] = 0;
    if (i < poly1.exponent) {
      difference.array[i] += poly1.array[i];
    }
    if (i < poly2.exponent) {
      difference.array[i] -= poly2.array[i];
    }
  }
  return difference;
}

const Polynomial operator*(const Polynomial& poly1, const Polynomial&poly2) {
 Polynomial product;
  product.exponent = poly1.exponent + poly2.exponent;
  delete [] product.array;
  product.array = new double[product.exponent];
  for (int i = 0; i < product.exponent; i++) {
    product.array[i] = 0;
  }
  for (int i = 0; i < poly1.exponent; i++) {
    for (int j = 0; j < poly2.exponent; j++) {
      product.array[i + j] += poly1.array[i] * poly2.array[j];
    }
  }
  return product;
}

ostream& operator<<(ostream& output, const Polynomial& poly) {
  poly.print();
  return output;
}