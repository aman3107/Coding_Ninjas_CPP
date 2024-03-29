#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
  T data;
  Node<T> *next;

  Node(T data)
  {
    this->data = data;
    this->next = NULL;
  }
};

template <typename T>

class Queue
{
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  Queue()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  int getSize()
  {
    return size;
  }

  bool isEmpty()
  {
    return size == 0;
  }

  T front()
  {
    if (isEmpty())
      return -1;
    return head->data;
  }

  void enqueue(T element)
  {
    Node<T> *newNode = new Node<T>(element);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
      size++;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
      size++;
    }
  }

  T dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty : " << endl;
      return 0;
    }
    T ans = head->data;
    Node<T> *temp = head;
    head = head->next;
    size--;
    delete temp;
    return ans;
  }
};