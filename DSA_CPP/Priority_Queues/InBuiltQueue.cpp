#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  // Max Heap
  // priority_queue<int> pq;
  // Min Heap
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(16);
  pq.push(1);
  pq.push(167);
  pq.push(45);
  pq.push(32);

  cout << "Size :" << pq.size() << endl;
  cout << "Top : " << pq.top() << endl;

  while (!pq.empty())
  {
    cout << pq.top() << " ";
    pq.pop();
  }
}