#include<iostream>
#include<stack>

using namespace std;

int main(){
  int data ;
  cin>>data;
  stack<int> s;
  while(data!=-1){
    s.push(data);
    cin>>data;
  }

  int x = s.size();

  while(x!=0){
    cout << "s.top:" << s.top() << endl;
    s.pop();
    x--;
  }

  cout << s.empty() << "<----" << "Stack empty" << endl;
}