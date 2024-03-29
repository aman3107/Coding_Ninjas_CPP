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

void deleteAlternateNodes(Node *head)
{
  if (head == NULL)
    return;
  Node *prev = head;
  Node *node = head->next;
  while (prev != NULL && node != NULL)
  {
    prev->next = node->next;
    prev = prev->next;

    if (prev != NULL)
    {
      node = prev->next;
    }
  }
}

int main()
{
  Node *head = takeInput();
  deleteAlternateNodes(head);
  print(head);
}