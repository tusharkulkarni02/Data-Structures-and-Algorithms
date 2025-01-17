#include<bits/stdc++.h>
using namespace std;

int fib_helper(int *ans, int n){ // top down apprach
  if(n<=1){
    return n;  // if N is less than one
  }

  if(ans[n]!=-1){
    return ans[n];   // if ans[n] already exists in the array return it directly
  }

  int a = fib_helper(ans, n-1); // call the n-1 number
  int b = fib_helper(ans, n-2); // call the n-2 number

  ans[n] = a+b; // store the result for current 'n' number 

  return ans[n]; // return
}

int fib(int n){
  int *ans = new int[n+1];
  for(int i=0;i<n+1;i++){
    ans[i] = -1; // initialise the array with -1
  }
  int res = fib_helper(ans,n);
  delete [] ans;
  return res; // call the helper func
}


int main(){
  int n;cin>>n;
  cout << fib(n) << endl; 
}