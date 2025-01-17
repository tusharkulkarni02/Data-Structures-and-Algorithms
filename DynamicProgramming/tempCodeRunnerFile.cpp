#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;  // define mod directly as an integer constant

int balancedBTs(int n) {
    vector<int> dp(n+1);  // initialize a dp array of n+1 size
    dp[0] = 1;
    dp[1] = 1;
 
    for(int i = 2; i <= n; i++) {
        int64_t a = dp[i-1]; // check for h-1 height
        int64_t b = dp[i-2]; // check for h-2 height

        int64_t temp1 = (a * a) % mod;   // multiplication of combination of (h-1)*(h-1)
        int64_t temp2 = (2 * a * b) % mod; // multiplication combination of (h-1)*(h-2) + (h-2)*(h-1)

        dp[i] = (temp1 + temp2) % mod; // finally add it to current height 'i'
    }
    return dp[n]; // return required height
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n) << endl;
}
