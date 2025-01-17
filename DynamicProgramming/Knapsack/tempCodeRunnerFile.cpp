#include<bits/stdc++.h>
using namespace std;


int knapsack(int *weights, int *values, int n, int maxWeight){
  int output[n+1][maxWeight+1];

  for(int j=0;j<=maxWeight;j++){
    output[n][j] = 0;
  }

  for(int i=n-1;i>=0;i--){
    for(int j=0;j<=maxWeight;j++){
      
      int with = 0;

      if(j>=weights[i]){
        with = output[i+1][j-weights[i]] + values[i];
      }

      int without = output[i+1][j];

      output[i][j] = max(with,without);
    }
  }

  return output[0][maxWeight];
}




int main(){
  int n;cin>>n;

  int *weights = new int[n];
  for(int i=0;i<n;i++){
    cin>>weights[i];
  }  

  int *values = new int[n];
  for(int i=0;i<n;i++){
    cin>>values[i];
  }

  int sackWeight; cin>>sackWeight;
  int res = knapsack(weights,values,n,sackWeight);
  cout << res << endl;
}