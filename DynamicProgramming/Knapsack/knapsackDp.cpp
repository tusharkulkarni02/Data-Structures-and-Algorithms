#include<bits/stdc++.h>
using namespace std;


int knapsack(int *weights, int *values, int n, int maxWeight){
  
  int output[n+1][maxWeight+1]; //declare 2D dp array

  for(int j=0;j<=maxWeight;j++){ // make the bottom row elements 0
    output[n][j] = 0; // this is the case when all the elements are rejected
  }

  for(int i=n-1;i>=0;i--){ // traverse from n-1 to 0 i.e bottom to top
    for(int j=0;j<=maxWeight;j++){ // traverse the array j represents the 
    // current maxWeight the sack can hold

      int with = 0; // initialize with = 0

      if(j>=weights[i]){ // if current maxWeight(j) of sack is less than the weight[i](current weight of the array)
        with = output[i+1][j-weights[i]] + values[i]; // calculate the output for 
        // i+1 th weight and j-weight[i] , by adding the curr weight value as we are considering it
      }

      int without = output[i+1][j]; // calculate the value without considerng the current weight

      output[i][j] = max(with,without); // return the max of both
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