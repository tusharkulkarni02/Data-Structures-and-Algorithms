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
  QueueUsingArray()
  {
    data = new T[1];
    nextIndex = 0;
    size = 0;
    capacity = 1;
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
      return;
    }
    if (size == capacity)
    {

      T *newdata = new T[2 * capacity];
      int k = 0;
      for (int i = firstIndex; i < capacity; i++)
      {
        newdata[k] = data[i];
        k++;
      }

      for (int i = 0; i < nextIndex; i++)
      {
        newdata[k] = data[i];
        k++;
      }
      delete[] data;
      data = newdata;
      firstIndex = 0;
      nextIndex = capacity;
      capacity *= 2;
    }
    data[nextIndex] = n;
    nextIndex++;
    nextIndex = (nextIndex) % capacity;
    size++;
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
  QueueUsingArray<int> q2;
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