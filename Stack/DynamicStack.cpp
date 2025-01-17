#include<iostream>
#include<climits>

using namespace std;

class stackarray{
  private:
  int *data;
  int capacity;
  int nextIndex;

  public:

  stackarray(int totalsize){
      data = new int[1];
      nextIndex = 0;
      capacity = 1;
  }

  int size(){
    return nextIndex;
  }

  bool isEmpty(){
    return nextIndex==0;
  }

  void push(int n){
    if(nextIndex==capacity){
      int *newdata = new int[2*capacity];
      for(int i=0;i<capacity;i++){
        newdata[i]=data[i];
      }
      capacity *= 2;
      delete [] data;
      data = newdata;
    }
    data[nextIndex]=n;
    nextIndex++;
  }


};