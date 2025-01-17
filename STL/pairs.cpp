#include<bits/stdc++.h>
using namespace std;

int totalSum(vector<vector<int>> input, int n) { 
	int sum = 0; 
	for (int i = 0; i < n; i++){ 
		sum += input[i][0]; 
		sum += input[i][n-1]; 
	} 
	for (int i =1; i<n-1; i++){ 
		sum += input[0][i];
		sum += input[n-1][i]; 
	} 
	for (int i=0; i<n; i++){ 
		sum += input[i][i]; 
		sum += input[i][n-1-i]; 
	} 
	if (n%2 != 0){ 
		sum -= input[n/2][n/2]; 
	} 

	return sum; 
}

int main (){

#ifndef ONLINE_JUDGE
	// For getting input form input1.txt
	freopen("input.txt","r",stdin);
	// For getting output form output1.txt
	freopen("output.txt","w",stdout);
#endif
	
	


	
		int n;
		cin >> n;
		vector<vector<int>> arr(n,vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        
        cout << totalSum(arr, n) << endl; 
	

}