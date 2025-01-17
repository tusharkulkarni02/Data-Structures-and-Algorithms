#include <bits/stdc++.h>
using namespace std;

int lis(int *arr, int n){

  vector<int>dp(n); // create a dp array of n size
  dp[0] = 1; // because till first element it 
  //will always be 1
  
  for(int i=1;i<n;i++){ // iterate from 1 to n-1 in dp array
    dp[i] = 1; // for single element least increasing subseq size will be 1
    for(int j=i-1;j>=0;j--){ // iterate in reverse order from i-1 to 0
      if(arr[j]>=arr[i]){ // check if previous element is greater than the ith element
        continue;// if greater then no need to consider in the ans
      }
      // if the element is smaller then check in the dp array
      // how much is the lenght of LIS till that element 
      // if LIS of that element + 1 is greater than LIS of dp[i]'th
      // the update the dp[i]

      int possibleAns = dp[j] + 1;
      if(possibleAns>dp[i]){
        dp[i] = possibleAns;
      }
    }
  }

  return *max_element(dp.begin(),dp.end()); // return the max LIS from the dp array 

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