#include<bits/stdc++.h> 
using namespace std;

template<typename T>

class stackUsingArray{
  private:

  T *data;
  int nextIndex;
  int capacity;

  public:

  stackUsingArray(int totalsize){
      data = new T[totalsize];
      nextIndex = 0;
      capacity = totalsize;
  }

  int size(){
    return nextIndex;
  }

  bool isEmpty(){
    return nextIndex==0;
  }

  void push(T n){
    if(nextIndex<capacity){
      data[nextIndex] = n;
      nextIndex++;
    }else{
      cout << "stack is full";
    }
  }

  T pop(){
    if(nextIndex==0){
      cout << "stack empty" << endl;
      return 0;
    }
    nextIndex--;
    return data[nextIndex];
  }

  T top(){
    if(nextIndex==0){
      cout << "stack empty" << endl;
      return 0;
    }
    return data[nextIndex-1];
  }

};

int main(){
  stackUsingArray<char> s(4);
  s.push(1);
  s.push(23);
  s.push(34);
  cout << "size:" << s.size() << endl;
  s.push(89);
  cout << "size:" << s.size() << endl;
  s.push(32);
  cout << "top:" << s.top()<<endl;
  

  s.pop();
  cout << "top:" << s.top() <<endl;
  
  cout << "pop:" << s.pop() << endl;
  cout << "pop:" << s.pop() << endl;
  cout << "pop:" << s.pop() << endl;
  cout << "pop:" << s.pop() << endl;

  cout << "isEmpty:" << s.isEmpty() << "\n\n\n\n";

  stackUsingArray<int> s1(4);
  s1.push(1);
  s1.push(23);
  s1.push(34);
  cout << "size:" << s1.size() << endl;
  s1.push(89);
  cout << "size:" << s1.size() << endl;
  s1.push(32);
  cout << "top:" << s1.top()<<endl;
  

  s1.pop();
  cout << "top:" << s1.top() <<endl;
  
  cout << "pop:" << s1.pop() << endl;
  cout << "pop:" << s1.pop() << endl;
  cout << "pop:" << s1.pop() << endl;
  cout << "pop:" << s1.pop() << endl;

  cout << "isEmpty:" << s1.isEmpty();
}

