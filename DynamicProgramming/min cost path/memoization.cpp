#include<bits/stdc++.h>
using namespace std;

int minCostHelper(int **input, int **matrix, int m, int n, int i, int j){
  if(i==m-1 && j==n-1){  // we reached the end of the matrix
    return input[i][j];
  }

  if(i>=m || j>=n){ // i or j exceeds more than m or n respectively
    return INT_MAX; // return int max
  }
  if(matrix[i][j]!=-1){ // if already present return directly
    return matrix[i][j]; 
  }

  int a = minCostHelper(input,matrix,m,n,i,j+1); // checking min Cost from right
  int b = minCostHelper(input,matrix,m,n,i+1,j+1); // checking min cost from diagonal
  int c = minCostHelper(input,matrix,m,n,i+1,j); // checking min cost from down

  int res = input[i][j] + min(a,min(b,c)); // add the min o/p of a,b,c with current cell of input

  matrix[i][j] = res; // store it for future use

  return matrix[i][j]; // return 
}


int minCostPath(int ** input, int m, int n){
  int **matrix = new int*[m];
  for(int i=0;i<m;i++){
    matrix[i] = new int[n];
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      matrix[i][j] = -1;
    }
  }
  return minCostHelper(input,matrix,m,n,0,0);
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
  cout << helper(input,m,n);
}