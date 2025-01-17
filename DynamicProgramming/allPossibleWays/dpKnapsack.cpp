#include<bits/stdc++.h>



int helper(int target, vector<int> powers){
	int n = powers.size();
	int dp[n+1][target+1];

	for(int j = 0; j<=target; j++){
		dp[n][j] = 0;
	}

	for(int i=0;i<=n;i++){
		dp[i][0] = 1;
	}

	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=target;j++){
			int ways = 0;
			if(powers[i]<=j){
				ways += dp[i+1][j-powers[i]];
			}
			ways += dp[i+1][j];
			dp[i][j] = ways;
		}
	}
	
	return dp[0][target];
	

}
int getAllWays(int a, int b) {
	vector<int> powers;
	int i=1;
	while(pow(i,b)<=a){
		powers.push_back(pow(i,b));
		i++;
	}
	int ways = 0;

	ways = helper(a,powers);

	return ways;
}
















