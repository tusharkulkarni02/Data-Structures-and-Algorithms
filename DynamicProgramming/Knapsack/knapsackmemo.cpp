#include <bits/stdc++.h>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxweights, int **output){
  // base case
	if(n==0 || maxweights<=0){ // if n==0 or maxwrightvalue is 0 or less than zero return 0 
    return 0;
  }
  if(output[n][maxweights]!=-1){ // if the value already exists
    return output[n][maxweights]; // return the value
  }
  int with = 0; // initialize with, with 0;
  if (maxweights >= weights[0]) { // if maxweight is greater than the weight[0] the call the func by 
  //subrtacting the weight[0] from maxweights and adding the result of the func with values[0]
    with = knapsack(weights + 1, values + 1, n - 1, maxweights - weights[0],output) + values[0];
  }
  int without = knapsack(weights + 1, values + 1, n - 1, maxweights, output); // to calculate the sum without considering 
  //the first value of the weight array move onto next elements 
  output[n][maxweights] = max(with,without); // this will contain the max value;

  return output[n][maxweights]; // return the max of with and without
}


int knapsack(int *weights, int *values, int n, int maxweights){
  
  int **output = new int*[n+1]; // declare the 2D array with row equal to n

  for(int i=0;i<=n;i++){
    output[i] = new int[maxweights+1]; // columns equal to the maximum weight of the sack
  }

  for(int i=0;i<=n;i++){
    for(int j=0;j<=maxweights;j++){
      output[i][j] = -1; // initialize all the values with -1
    }
  }

  int res = knapsack(weights,values,n,maxweights,output);
  delete output;
  return res;

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