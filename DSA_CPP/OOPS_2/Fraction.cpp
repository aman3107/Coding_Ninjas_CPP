#include <iostream>
using namespace std;

class Fraction
{
private:
  int numerator, denominator;

public:
  Fraction(int numerator, int denominator)
  {
    this->numerator = numerator;
    this->denominator = denominator;
  }

  void print()
  {
    cout << this->numerator << " / " << this->denominator << endl;
  }

  void simplify()
  {
    int gcd = 1;
    int j = min(this->numerator, this->denominator);
    for (int i = 1; i <= j; i++)
    {
      if (this->numerator % i == 0 && this->denominator % i == 0)
      {
        gcd = i;
      }
    }
    this->numerator = this->numerator / gcd;
    this->denominator = this->denominator / gcd;
  }

  Fraction add(Fraction const &f2) const
  {
    int lcm = this->denominator * f2.denominator;
    int x = lcm / this->denominator;
    int y = lcm / f2.denominator;
    int num = x * this->numerator + (y * f2.numerator);
    Fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;
  }
  Fraction operator+(Fraction const &f2) const
  {
    int lcm = this->denominator * f2.denominator;
    int x = lcm / this->denominator;
    int y = lcm / f2.denominator;
    int num = x * this->numerator + (y * f2.numerator);
    Fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;
  }

  Fraction operator*(Fraction const &f2) const
  {
    int n = this->numerator * f2.numerator;
    int d = this->denominator * f2.denominator;
    Fraction fNew(n, d);
    fNew.simplify();
    return fNew;
  }

  bool operator==(Fraction const &f2)
  {
    return (this->numerator == f2.numerator && this->denominator == f2.denominator);
  }

  // Pre Increment Operator
  Fraction &operator++()
  {
    this->numerator = this->numerator + this->denominator;
    simplify();
    return *this;
  }

  // Post Increment Operator
  Fraction operator++(int)
  {
    Fraction fNew(numerator, denominator);
    numerator = numerator + denominator;
    simplify();
    fNew.simplify();
    return fNew;
  }

  Fraction &operator+=(Fraction const &f2)
  {
    int lcm = denominator * f2.denominator;
    int x = lcm / denominator;
    int y = lcm / f2.denominator;
    int num = x * numerator + (y * f2.numerator);

    numerator = num;
    denominator = lcm;
    simplify();
    return *this;
  }
};