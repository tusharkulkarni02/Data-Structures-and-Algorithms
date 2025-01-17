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
    next = NULL;
  }
};

template <typename T>

class Queue
{
private:
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

  void enqueue(T n)
  {
    Node<T> *newNode = new Node<T>(n);
    if (head == NULL)
    {
      head = newNode;
      tail = head;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }

  T dequeue()
  {
    if (head == NULL)
    {
      cout << "queue empty!" << endl;
      return -1;
    }
    else
    {
      T ans = head->data;
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      size--;
      return ans;
    }
  }
  T front()
  {
    if (head == NULL)
    {
      cout << "queue is empty" << endl;
      return -1;
    }
    else
    {
      return head->data;
    }
  }
  int getsize()
  {
    return size;
  }

  bool isEmpty()
  {
    return size == 0;
  }
};

int main()
{
  Queue<int> q;
  int data;
  cin >> data;
  while (data != -1)
  {
    q.enqueue(data);
    cin >> data;
  }
  cout << "front:" << q.front() << endl;
  cout << "q.getsize()" << q.getsize() << endl;
  while (!q.isEmpty())
  {
    cout << "dequeued data: " << q.dequeue() << endl;
  }

  cout << "q.isEmpty()" << q.isEmpty() << endl;
}