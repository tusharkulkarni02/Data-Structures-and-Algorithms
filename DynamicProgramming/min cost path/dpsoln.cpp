#include<bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n){
  int **output = new int*[m];
  for(int i=0;i<m;i++){
    output[i] = new int[n];
  }
  
  output[m-1][n-1] = input[m-1][n-1]; // initialize the last element of the array

  // fill the last row of the array by adding the current cell with its next cell of the same row
  for(int j=n-2;j>=0;j--){
    output[m-1][j] = input[m-1][j] + output[m-1][j+1]; 
  }

  // fill the last column of the array by adding the current cell with its next cell of the same colume
  for(int i=m-2;i>=0;i--){
    output[i][n-1] = input[i][n-1] + output[i+1][n-1];
  }

  // fill the rest of the output matrix

  for(int i=m-2;i>=0;i--){
    for(int j=n-2;j>=0;j--){
      output[i][j]  = input[i][j] + min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]));
    }
  }

  return output[0][0];
}

int main(){
  int m,n;cin>>m>>n;
  int **input = new int*[m];
  for(int i=0;i<m;i++){
    input[m] = new int[n];
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>input[i][j];
    }
  }
  cout << minCostPath(input,m,n);
}