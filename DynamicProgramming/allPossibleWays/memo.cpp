#include<bits/stdc++.h>

int helper(int target, vector<int> powers, int idx, int **output){
	if(target==0) return 1;
	if(idx==powers.size()) return 0;

	if(output[idx][target]!=-1){
		return output[idx][target];
	}

	int ways = 0;
	if(powers[idx]<=target){
		ways+= helper(target-powers[idx],powers, idx+1,output);
	}
    ways += helper(target,powers,idx+1,output);

	output[idx][target] = ways;
	return output[idx][target];
}

int getAllWays(int a, int b) {
	// Write your code here
	vector<int> powers;
	int i=1;
	while(pow(i,b)<=a){
		powers.push_back(pow(i,b));
		i++;
	}
	int ways = 0;

	int **output = new int*[powers.size()+1];
	for(int i=0;i<powers.size()+1;i++){
		output[i] = new int[a+1];
	}

	for(int i=0;i<=powers.size();i++){
		for(int j=0;j<=a;j++){
			output[i][j] = -1;
		}
	}

	ways = helper(a,powers,0,output);

	return ways;
}