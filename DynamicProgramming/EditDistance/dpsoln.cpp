#include<bits/stdc++.h>
using namespace std;



int minChanges(string s, string t){
  int m = s.size(), n = t.size();
  int output[m+1][n+1]; // prepare a 2D array of m+1 rows and n+1 colms
  
  for(int j=0;j<=n;j++){
    output[0][j] = j;  // fill all the columns of first row serialy
  }

  for(int i=0;i<=m;i++){
    output[i][0] = i; // fill all the rows of first column serialy
  }

  for(int i=1;i<=m;i++){ // traverse from 2nd row 2nd col to m row , n th col
    for(int j=1;j<=n;j++){
      if(s[m-i]==t[n-j]){  // if first char of the strings are equal, 
        // since the i&j represent length of remaining
        // string then , doing m-i and n-j 
        // will give us the first characters of the remaining strings.
        output[i][j] = output[i-1][j-1]; // just copy the i-1 and j-1 ans
      }
      else{
        int a = output[i-1][j] + 1; // insert 
        int b = output[i][j-1] + 1; // delete
        int c = output[i-1][j-1] + 1; // replace
        output[i][j] = min(a,min(b,c)); // add the min of the above three
      }
    }
  }

  return output[m][n]; // return the final ans which is kept in at the mth row and nth column.

}






int main(){
  string s,t;
  cin>>s>>t;

  int n = minChanges(s,t);
  cout << n << endl;
}