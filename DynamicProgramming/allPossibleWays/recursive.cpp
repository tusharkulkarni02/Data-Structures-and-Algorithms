#include<bits/stdc++.h>

int helper(int target, vector<int> powers, int idx){
	if(target==0) return 1;
	if(idx==powers.size()) return 0;
	int ways = 0;
	if(powers[idx]<=target){
		ways+= helper(target-powers[idx],powers, idx+1);
	}
    ways += helper(target,powers,idx+1);
	return ways;
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
	ways = helper(a,powers,0);
	return ways;
}