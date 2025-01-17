#include <iostream>
using namespace std;


int helper(int **input, int m, int n, int i, int j){
  if(i==m-1 && j==n-1){
    return input[i][j];
  }

  if(i>=m || j>=n){
    return INT_MAX;
  }

  int minRight = helper(input,m,n,i,j+1);

	int minDia = helper(input,m,n,i+1,j+1);

	int minDown = helper(input,m,n,i+1,j);

	int minSum =  min(minRight,min(minDia,minDown));

	return input[i][j] + minSum;
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
  cout << helper(input,m,n,0,0);
}