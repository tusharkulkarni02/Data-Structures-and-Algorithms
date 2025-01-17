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
class StackUsingLL
{

private:
  Node<T> *head;
  int size;

public:
  StackUsingLL()
  {
    head = NULL;
    size = 0;
  }
  void push(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    if (head == NULL)
    {
      head = newNode;
      size = 1;
    }
    else
    {
      newNode->next = head;
      head = newNode;
      size++;
    }
  }

  T pop()
  {
    if (head == NULL)
    {
      cout << "stack is Empty"
           << "\n";
      return 0;
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

  T top()
  {
    if (head == NULL)
    {
      cout << "stack is Empty"
           << "\n";
      return 0;
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
    return head == NULL;
  }
};

int main()
{

  StackUsingLL<int> s1;
  cout << "size: " << s1.getsize() << '\n';

  s1.push(23);

  cout << "size: " << s1.getsize() << '\n';

  s1.pop();
  cout << "size: " << s1.getsize() << '\n';

  s1.push(234);
  s1.push(96);
  s1.push(66);
  s1.push(34);

  cout << "size: " << s1.getsize() << '\n';

  cout << "top: " << s1.top() << '\n';

  cout << s1.pop() << '\n';

  cout << s1.pop() << '\n';
  cout << s1.pop() << '\n';
  cout << s1.pop() << '\n';
  cout << s1.pop() << '\n';

  cout << s1.top() << '\n';

  StackUsingLL<char> s2;
  cout << "size: " << s2.getsize() << '\n';

  s2.push(23);

  cout << "size: " << s2.getsize() << '\n';

  s2.pop();
  cout << "size: " << s2.getsize() << '\n';

  s2.push('a');
  s2.push('b');
  s2.push('c');
  s2.push('d');

  cout << "size: " << s2.getsize() << '\n';

  cout << "top: " << s2.top() << '\n';

  cout << s2.pop() << '\n';

  cout << s2.pop() << '\n';
  cout << s2.pop() << '\n';
  cout << s2.pop() << '\n';
  cout << s2.pop() << '\n';

  cout << s2.isEmpty() << endl;
  cout << s2.top() << '\n';
}