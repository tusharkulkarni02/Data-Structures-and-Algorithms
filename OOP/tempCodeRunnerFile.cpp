#include<bits/stdc++.h>
using namespace std;

class Fraction{
    private:
    int numerator=0; 
    int denominator=0;

    public:
    Fraction(int num,int den){
      numerator=num; denominator=den;
    }

    void display(){
      cout << numerator << "/" << denominator << endl;
    }
    void simplify(){
      int x=0;
      (numerator>=denominator)? x=denominator : x=numerator;
      int i=2;
      int gcd = 1;
      for(int i=2;i<x;i++){
        if(numerator%i==0 && denominator%i==0){
            gcd=i;
        }
      }
      numerator/=gcd;
      denominator/=gcd;
    }

    void add(const Fraction &f2){
       numerator = numerator*f2.denominator + denominator*f2.numerator;
       denominator = denominator*f2.denominator;
       simplify();
    }

    void multiply(const Fraction &f2){
      numerator = numerator*f2.numerator;
      denominator = denominator*f2.denominator;
      simplify();
    }
};

int main(){
  Fraction f1(2,10);
  Fraction f2(5,20);
  f1.add(f2);
  f1.simplify();
  f1.display();

  f1.multiply(f2);
  f1.simplify();
  f1.display();

}