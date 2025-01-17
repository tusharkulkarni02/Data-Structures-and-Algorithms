#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubseq(string s, string t){
  if(s.empty() || t.empty()){ // if any of the two string is empty
    return 0;
  }
  
  if(s[0]==t[0]){ // if first char of both string is equal
    return 1+LongestCommonSubseq(s.substr(1),t.substr(1));
  }else{
    int a = LongestCommonSubseq(s,t.substr(1)); // check for rest of the t string 
    int b = LongestCommonSubseq(s.substr(1),t); // check for rest of the s string
    int c = LongestCommonSubseq(s.substr(1),t.substr(1)); // check for rest of the both strings
    // c step in not really required as it is handled internally by the upper cases
    return max(a,max(b,c)); // return max of all the strings
  }
  
}





int main(){
  string s;
  cin>>s;
  string t;
  cin>>t;
  cout << LongestCommonSubseq(s,t) << endl;
}