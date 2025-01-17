#include<bits/stdc++.h>
using namespace std;


int main (){

#ifndef ONLINE_JUDGE
	// For getting input form input1.txt
	freopen("input1.txt","r",stdin);
	// For getting output form output1.txt
	freopen("output1.txt","w",stdout);
#endif
	int r, c;
	cin >> r >> c;
	
	// Method 1  ######PEOPLE PREFER THIS#######
	// Defining an array of vector
	// vector<int> arr[r];
	// for (int i=0; i<r; i++) arr[i].resize(c);
	
	// Method 2
	// Defining a vector of vector
	vector<vector<int> > arr( r , vector<int> (c));
	
	for(int i=0; i<r; i++)
		for (int j=0; j<c; j++) cin >> arr[i][j];
			

	for (int i=0; i<r; i++){
		int sum =0;
		for (int j=0; j<c; j++) sum += arr[i][j];
		cout << sum << endl;
	}
}