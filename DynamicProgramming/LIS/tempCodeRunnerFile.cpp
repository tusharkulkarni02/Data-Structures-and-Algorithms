#include <bits/stdc++.h>
using namespace std;

int lis(int *arr, int n){

  vector<int>dp(n);
  dp[0] = 1;
  
  for(int i=1;i<n;i++){
    dp[i] = 1;
    for(int j=i-1;j>=0;j--){
      if(arr[j]>=arr[i]){
        continue;
      }
      int possibleAns = dp[j] + 1;
      if(possibleAns>dp[i]){
        dp[i] = possibleAns;
      }
    }
  }

  return *max_element(dp.begin(),dp.end());

}



int main(){
  int n;
  cin>>n;

  int *arr = new int[n];

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int ans = lis(arr, n);

  cout << ans << endl;

  delete[]arr;

}