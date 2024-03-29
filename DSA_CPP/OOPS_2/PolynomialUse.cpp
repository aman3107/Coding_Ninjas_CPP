#include <iostream>
#include "Polynomial.cpp"
using namespace std;

int main()
{
  int count1, count2, choice;
  cin >> count1;

  int *degree1 = new int[count1];
  int *coeff1 = new int[count1];

  for (int i = 0; i < count1; i++)
  {
    cin >> degree1[i];
  }

  for (int i = 0; i < count1; i++)
  {
    cin >> coeff1[i];
  }

  Polynomial first;
  for (int i = 0; i < count1; i++)
  {
    first.setCoefficient(degree1[i], coeff1[i]);
  }

  cin >> count2;

  int *degree2 = new int[count2];
  int *coeff2 = new int[count2];

  for (int i = 0; i < count2; i++)
  {
    cin >> degree2[i];
  }

  for (int i = 0; i < count2; i++)
  {
    cin >> coeff2[i];
  }

  Polynomial second;
  for (int i = 0; i < count2; i++)
  {
    second.setCoefficient(degree2[i], coeff2[i]);
  }
  Polynomial result1 = first + second;
  result1.print();

  Polynomial result2 = first - second;
  result2.print();

  Polynomial result3 = first * second;
  result3.print();
}