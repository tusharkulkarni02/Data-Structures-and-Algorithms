
int helper(int denominations[],int numDenominations, int value, int idx, int **output){
	if(value == 0){
		return 1;
	}
	if(denominations[idx]>value || idx==numDenominations){
		return 0;
	}
	if(output[idx][value]!=-1){
		return output[idx][value];
	}

	int ways = 0;
	ways += helper(denominations,numDenominations, value-denominations[idx], idx,output);
	ways += helper(denominations,numDenominations,value, idx+1,output);

	output[idx][value] =  ways;

	return output[idx][value];
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	const int Mod = 1e9+7;
	int **output = new int*[numDenominations+1];
	for(int i=0;i<=numDenominations;i++){
		output[i] = new int[value+1];
	}
	for(int i=0;i<=numDenominations;i++){
		for(int j=0;j<=value;j++){
			output[i][j] = -1;
		}
	}
	int ans = helper(denominations,numDenominations,value,0,output);
	return ans;
}