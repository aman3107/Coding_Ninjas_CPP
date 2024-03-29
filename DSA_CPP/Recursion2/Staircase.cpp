#include <iostream>
using namespace std;

int staircase(int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  int x = staircase(n - 1);
  int y = staircase(n - 2);
  int z = staircase(n - 3);
  return x + y + z;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int ans = staircase(n);
  cout << ans << endl;
}