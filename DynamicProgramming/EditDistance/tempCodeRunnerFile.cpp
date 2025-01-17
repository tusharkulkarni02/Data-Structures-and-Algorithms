#include<bits/stdc++.h>
using namespace std;



int minChanges(string s, string t){
  int m = s.size(), n = t.size();
  int output[m+1][n+1];
  
  for(int j=0;j<=n;j++){
    output[0][j] = j;
  }

  for(int i=0;i<=m;i++){
    output[i][0] = i;
  }

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(s[m-i]==t[n-j]){
        output[i][j] = output[i-1][j-1];
      }
      else{
        int a = output[i-1][j] + 1;
        int b = output[i][j-1] + 1;
        int c = output[i-1][j-1] + 1;
        output[i][j] = min(a,min(b,c));
      }
    }
  }

  return output[m][n];

}






int main(){
  string s,t;
  cin>>s>>t;

  int n = minChanges(s,t);
  cout << n << endl;
}