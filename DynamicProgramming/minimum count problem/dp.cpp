#include<bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	vector<int> dp(n+1,INT_MAX);  // initialize the dp array with values of INT_MAX
	dp[0]=0; // base case equal to zero
	for(int i=1;i<=n;i++){  // loop from 1  till n

		for(int j=1;j*j<=i;j++){ // find out squares till i
			int x = j*j; // calculate square of j
			if(i-x >= 0) dp[i] = min(dp[i],dp[i-x]+1); // calculate the minimum
			else break;
		}
	}
	return dp[n];
}
int main(){
  int n;cin>>n;
  cout<< minCount(n) << endl;
}