#include<bits/stdc++.h>
using namespace std;

int longestCommonSubseq(string s, string t){
  int m = s.size();// m is size of the string s
  int n = t.size();// n is size of the string t

  int output[m+1][n+1]; // create a 2D Dp array of m+1 rows and n+1 columns
  
  for(int j=0;j<=n;j++){// for first row all the elements are 0 as the length of string s is 0
    output[0][j] = 0;  
  }

  for(int i=0;i<=m;i++){// for first column all the elements are 0
  // as the lenght of the string t is 0
    output[i][0] = 0;
  }

  for(int i=1;i<=m;i++){ // for string s length 1 to m 
    for(int j=1;j<=n;j++){ // for string t length 1 to n
      if(s[m-i] == t[n-j]){  // here we are checking the first character of the string for length i & j
      // respectively
      //      ___________________        _____________________
      // eg: | s = T u s h a r   |      | t = R o c k h a r d |
      //     |     0 1 2 3 4 5   |      |     0 1 2 3 4 5 6 7 |
      //     | s = 6 (lenght(m)) |      | t = 8 (lenght(n))   | 
      //     |___________________|      |_____________________|
      //      _____________________      _______________________
      //     | i = h a r (length=3)|    | j = h a r d (lenght=4)|
      //     | m-i = 6-3 = 3       |    | n-j = 8-4 = 4         |
      //     | s[m-i] = s[3] = h   |    | t[n-j] = t[4] = h     | 
      //     |_____________________|    |_______________________|
      // thus we have proved why we do m-i and n-j to check first characters of remaining strings
        
        output[i][j] = 1 + output[i-1][j-1]; // if matches add 1 + the output where both the characters 
        // are excluded in both the string  
      
      }else{ // if the first characters dont match
        int a = output[i-1][j]; // check for rest of the s string 
        int b = output[i][j-1]; // for rest of the t string 
        int c = output[i-1][j-1]; // and excludin both the first characters
        output[i][j] = max(a,max(b,c)); //  max of all the three
      }
    }
  }
  return output[m][n]; //  return the output for the original string of size m and n
}



int main(){
  string s;
  cin>>s;
  string t;
  cin>>t;
  cout << longestCommonSubseq(s,t) << endl;
}