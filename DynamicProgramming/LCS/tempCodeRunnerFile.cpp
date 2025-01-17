#include<bits/stdc++.h>
using namespace std;

int longestCommonSubseq(string s, string t){
  int m = s.size();
  int n = t.size();

  int output[m+1][n+1];
  
  for(int j=0;j<=n;j++){
    output[0][j] = 0; 
  }

  for(int i=0;i<=m;i++){
    output[i][0] = 0;
  }

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(s[m-i] == t[n-j]){
        output[i][j] = 1 + output[i-1][j-1];
      }else{
        int a = output[i-1][j];
        int b = output[i][j-1];
        int c = output[i-1][j-1];
        output[i][j] = max(a,max(b,c));
      }
    }
  }
  return output[m][n];
}



int main(){
  string s;
  cin>>s;
  string t;
  cin>>t;
  cout << longestCommonSubseq(s,t) << endl;
}