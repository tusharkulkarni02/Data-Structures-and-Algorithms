
int helper(int denominations[],int numDenominations, int value, int idx, int **output){
	if(value == 0){
		return 1;
	}
	if(denominations[idx]>value || idx==numDenominations){
		return 0;
	}

	int ways = 0;
	ways += helper(denominations,numDenominations, value-denominations[idx], idx);
	ways += helper(denominations,numDenominations,value, idx+1);

	return ways;
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){

	int ans = helper(denominations,numDenominations,value,0);
	return ans;
}