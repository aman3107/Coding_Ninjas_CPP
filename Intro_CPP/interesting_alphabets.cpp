#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int i = 1;
  while (i <= n)
  {
    int j = 1;
    char ch = 'A' + (n - 1) - (i - 1);
    while (j <= i)
    {
      cout << ch << " ";
      j++;
      ch++;
    }
    cout << endl;
    i++;
  }
}