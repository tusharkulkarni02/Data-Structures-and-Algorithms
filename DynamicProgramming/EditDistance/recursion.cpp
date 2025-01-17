#include<bits/stdc++.h>
using namespace std;

int minChanges(string s, string t){
  if(s.empty() || t.empty()){ // if any of the string is empty
    return max(s.size(),t.size()); // return max size if both strings
  }

  if(s[0]==t[0]){ // if first char is same , not need to edit
    return minChanges(s.substr(1),t.substr(1)); //  move on to the rest of the both strings
  }
  else{
    int a = minChanges(s.substr(1),t) + 1; // insert  => this means adding a char equal to the first char of stirng s to t
    int b = minChanges(s,t.substr(1)) + 1; // delete  => deleting the fitst char of string t
    int c = minChanges(s.substr(1),t.substr(1)) + 1; // replace => replacing the first character with first char of s

    return min(a,min(b,c));// return min of all operations


    /*If The above is tough to visualize , then check this out 

    int a = editDistance(s1.substr(1),s2); // call the funciton by removing the first char of s
		int b = editDistance(s1,s2.substr(1)); // call the func by removing the first char of t
		int c = editDistance(s1.substr(1),s2.substr(1)); // call the func by removing the first char of both strings

		return 1 + min(a,min(b,c)); // return the min of all three + 1 (becoz we are performing one operation of delete
    , replace or insert befort calling the above functions)
    */
  }
  
}

int main(){
  string s,t;
  cin>>s>>t;

  int n = minChanges(s,t);
  cout << n << endl;
}