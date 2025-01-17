
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

	int dp[numDenominations+1][value+1];

	for(int i=0;i<=numDenominations;i++){
		dp[i][0] = 1;
	}

	for(int j=0;j<=value;j++){
		dp[numDenominations][j] = 0;
	}

	for(int i=numDenominations-1;i>=0;i--){
		for(int j=1;j<=value;j++){
			int ways = 0;
			if(denominations[i]<=j){
				ways += dp[i][j-denominations[i]];
			}
			ways+= dp[i+1][j];
			dp[i][j] = ways;
		}
	}

	return dp[0][value];

}



// int helper(int denominations[],int numDenominations, int value, int idx, int **output){
// 	if(value == 0){
// 		return 1;
// 	}
// 	if(denominations[idx]>value || idx==numDenominations){
// 		return 0;
// 	}
// 	if(output[idx][value]!=-1){
// 		return output[idx][value];
// 	}

// 	int ways = 0;
// 	ways += helper(denominations,numDenominations, value-denominations[idx], idx,output);
// 	ways += helper(denominations,numDenominations,value, idx+1,output);

// 	output[idx][value] =  ways;

// 	return output[idx][value];
// }


// int countWaysToMakeChange(int denominations[], int numDenominations, int value){
// 	const int Mod = 1e9+7;
// 	int **output = new int*[numDenominations+1];
// 	for(int i=0;i<=numDenominations;i++){
// 		output[i] = new int[value+1];
// 	}
// 	for(int i=0;i<=numDenominations;i++){
// 		for(int j=0;j<=value;j++){
// 			output[i][j] = -1;
// 		}
// 	}
// 	int ans = helper(denominations,numDenominations,value,0,output);
// 	return ans;
// }