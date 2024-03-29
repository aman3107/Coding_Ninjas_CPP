#include <iostream>
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

void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *insert(Node *head, int i, int data)
{
  int c = 1;
  Node *newNode = new Node(data);
  Node *temp = head;

  if (i == 0)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    while (c < i && temp != NULL)
    {
      temp = temp->next;
      c++;
    }
    if (temp != NULL)
    {
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  print(head);
  int data;
  cin >> data;
  int index;
  cin >> index;
  head = insert(head, index, data);
  print(head);
}