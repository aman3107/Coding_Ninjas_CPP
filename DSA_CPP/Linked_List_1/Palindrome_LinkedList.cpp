#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

Node *takeInput()
{
  int data;
  cin >> data;
  Node *head = NULL;
  Node *tail = NULL;

  while (data != -1)
  {
    Node *newNode = new Node(data);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    cin >> data;
  }
  return head;
}

bool isPalindrome(Node *head)
{
  // Write your code here
  vector<int> vec;
  Node *temp = head;
  bool pal = true;
  while (temp != NULL)
  {
    vec.push_back(temp->data);
    temp = temp->next;
  }
  temp = head;
  for (int i = vec.size() - 1; i >= 0; i--)
  {
    if (temp->data == vec[i])
    {
      temp = temp->next;
      pal = true;
    }
    else
    {
      temp = temp->next;
      pal = false;
      return pal;
    }
  }
  return pal;
}

int main()
{
  Node *head = takeInput();
  if (isPalindrome(head))
    cout << "Palindrome " << endl;
  else
    cout << "Not Palindrome " << endl;
}