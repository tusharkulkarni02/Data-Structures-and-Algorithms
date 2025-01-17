#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int arr[2*n+1];
  for(int i=0;i<2*n+1;i++) cin >> arr[i];
  
  
  // FIRST APPROACH
  
  sort(arr,arr+2*n+1);
  bool flag = false;
  for (int i=0; i<n; i++){
    int F = 2*i, S = F+1;
    if (arr[F]!=arr[S]){
      flag = true;
      cout << arr[F] << endl;
      break;
    }
  }
  if (flag==false) cout << arr[2*n] << endl;


// SECOND APPROACH

int result=0;
for (int i=0; i<2*n+1;i++){
  result = result ^ arr[i];
}
cout << result << endl;
}