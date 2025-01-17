#include <bits/stdc++.h>
using namespace std;


// int findMaxvaluesum(int *weights, int *values,int n, int sackweights, int sum){
//   if(n==0 || sackweights<=0){ // if array is completely traversed or sackweight is less than or equal to zero.
//     return sum; // return sum
//   }

//   int without = findMaxvaluesum(weights+1,values+1,n-1,sackweights,sum); // here the calculate the sum without considering the first element
//   int with = 0;
//   if(sackweights-weights[0]>=0){ // if the sack weight is greater than the first element , the we calcualate the final sum by adding the first value of the weights array
//     with = findMaxvaluesum(weights+1,values+1,n-1,sackweights-weights[0],sum+values[0]);
//   }
//   return max(without,with); // which ever has the maximum output is returned
// }

// int knapsack(int *weights, int *values, int n, int maxweights)
// {
// 	int sum = 0; // declare and initilaize the sum
// 	int res = findMaxvaluesum(weights, values, n, maxweights, sum); // call the func
// 	return res; // return the result
// } ^^^^^^^^^^^^^^^^^ MY CODE


int knapsack(int *weights, int *values, int n, int maxweights)
{
	if(n==0 || maxweights<=0){ // if n==0 or maxwrightvalue is 0 or less than zero return 0 
    return 0;
  }

  int with = 0; // initialize with, with 0;
  if (maxweights >= weights[0]) { // if maxweight is greater than the weight[0] the call the func by 
  //subrtacting the weight[0] from maxweights and adding the result of the func with values[0]
    with = knapsack(weights + 1, values + 1, n - 1, maxweights - weights[0]) + values[0];
  }
  int without = knapsack(weights + 1, values + 1, n - 1, maxweights); // to calculate the sum without considering 
  //the first value of the weight array move onto next elements 

  return max(with,without); // return the max of with and without
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