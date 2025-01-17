#include<bits/stdc++.h>
using namespace std;


int helper(vector<int> &ans, int n){
	if(n<=3){
		return n;
	}

	if(ans[n]!=-1){
		return ans[n];
	}
	
	int minCnt = INT_MAX;

	for(int i=1;i*i<=n;i++){
		minCnt = min(minCnt,1+helper(ans,n-i*i));
	}
	ans[n] = minCnt;
	return ans[n];
} 



int minCount(int n)
{
	vector<int> ans(n+1,-1);

	return helper(ans,n);	
}



int main(){
  int n;cin>>n;
  cout << minCount(n) << endl;
}