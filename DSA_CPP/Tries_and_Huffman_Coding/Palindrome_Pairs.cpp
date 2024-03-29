#include <iostream>
#include <vector>
#include "Trie.h"
#include <string>
using namespace std;

int main()
{
  Trie t;
  int n;
  cin >> n;
  vector<string> words(n);

  for (int i = 0; i < n; ++i)
  {
    cin >> words[i];
  }

  cout << (t.isPalindromePair(words) ? "true" : "false");
}