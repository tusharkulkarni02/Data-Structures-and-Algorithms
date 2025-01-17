#include <iostream>
using namespace std;
template <typename T>

class QueueUsingArray
{
  T *data;
  int nextIndex;
  int firstIndex;
  int capacity;
  int size;

public:
  QueueUsingArray(T totalsize)
  {
    data = new T[totalsize];
    nextIndex = 0;
    size = 0;
    capacity = totalsize;
    firstIndex = -1;
  }

  void enqueue(T n)
  {
    if (firstIndex == -1)
    {
      firstIndex++;
      firstIndex = (firstIndex) % capacity;
      data[firstIndex] = n;
      nextIndex++;
      nextIndex = (nextIndex) % capacity;
      size++;
    }
    else if (size < capacity)
    {
      data[nextIndex] = n;
      nextIndex++;
      nextIndex = (nextIndex) % capacity;
      size++;
    }
    else
    {
      cout << "Queue is full! " << n << " cannot be inserted" << endl;
    }
  }

  T dequeue()
  {
    if (size == 0)
    {
      cout << "Queue cannot be dequeued: size is 0!" << endl;
      return -1;
    }
    else
    {
      T ans = data[firstIndex];
      firstIndex++;
      firstIndex = (firstIndex) % capacity;
      size--;
      return ans;
    }
  }

  T front()
  {
    if (size == 0)
    {
      return -1;
    }
    else
    {
      T ans = data[firstIndex];
      return ans;
    }
  }

  T getsize()
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

  // QueueUsingArray<int> q1(5);
  // q1.enqueue(1);
  // q1.enqueue(2);
  // q1.enqueue(3);
  // q1.enqueue(4);
  // q1.enqueue(5);
  // q1.enqueue(6);

  // while (!q1.isEmpty())
  // {
  //   cout << q1.dequeue() << endl;
  // }
  // q1.enqueue(1);
  // q1.enqueue(2);
  // q1.enqueue(3);
  // q1.enqueue(4);
  // q1.enqueue(5);
  // cout << "front:" << q1.front() << endl;
  // while (!q1.isEmpty())
  // {
  //   cout << q1.dequeue() << endl;
  //   cout << "front:" << q1.front() << endl;
  // }

  // q1.enqueue(1);
  // q1.enqueue(2);
  // q1.enqueue(3);
  // q1.enqueue(4);
  // q1.enqueue(5);
  // while (!q1.isEmpty())
  // {
  //   cout << q1.dequeue() << endl;
  // }
  // cout << "front:" << q1.front() << endl;
  // cout << q1.dequeue() << endl;

  QueueUsingArray<int> q2(5);
  int data;
  cin >> data;
  while (data != -1)
  {
    q2.enqueue(data);
    cin >> data;
  }
  cout << q2.front() << endl;
  cout << q2.dequeue() << endl;
  cout << q2.dequeue() << endl;
  cout << q2.dequeue() << endl;

  cout << q2.getsize() << endl;
  cout << q2.isEmpty() << endl;
}