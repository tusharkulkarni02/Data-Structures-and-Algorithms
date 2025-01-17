#include <iostream>
#include <queue>

using namespace std;

int main()
{
  queue<int> q;
  int data;
  cin >> data;
  while (data != -1)
  {
    q.push(data);
    cin >> data;
  }
  cout << q.front() << endl;
  cout << "size:" << q.size() << endl;

  while (!q.empty())
  {
    q.pop();
  }
  cout << q.front() << endl;
  q.pop();
}