#include<bits/stdc++.h>
using namespace std;

int minCount(int n)
{	
	if(n<=2){
		return n;
	}

	int num = sqrt(n);
	if(num*num==n){
		return 1;
	}

	int cnt = INT_MAX;
	for(int i=1;i*i<n;i++){
		int res = minCount(n-(i*i));
		if(res<cnt){
			cnt=res;
		}
	}
	return 1+cnt;	
}


int main(){
  int n;
  cin>>n;
  cout << "Recursive:" << minCount(n) << endl;
}