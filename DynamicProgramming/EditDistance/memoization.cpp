#include<bits/stdc++.h>
using namespace std;

int minChanges(string s, string t, int **output){
  int m = s.size() , n = t.size();
  if(m==0 || n==0){ // if any of the string is empty , return the size of the other
    return max(m,n);
  }

  if(output[m][n]!=-1){ // if the ans for the current strings exist return directly
    return output[m][n];
  }

  int ans; // declare ans which stores output of further calls
  if(s[0]==t[0]){ // if the first characters are same , nove onto rest of the strings
    ans = minChanges(s.substr(1),t.substr(1),output);
  }else{
    int a = minChanges(s.substr(1),t,output) + 1; // insert operation
    int b = minChanges(s,t.substr(1),output) + 1; // delete operation
    int c = minChanges(s.substr(1),t.substr(1),output) + 1; // remove operation

    ans = min(a,min(b,c)); // store the min of these a,b,c
  }

  output[m][n] = ans; // store the ans in output 2D dp array , for future use
  return output[m][n]; //  return the ans
}



int minChanges(string s, string t){
  int **output = new int*[s.size()+1];
  for(int i=0;i<=s.size();i++){
    output[i] = new int[t.size()+1];
  }
  for(int i=0;i<=s.size();i++){
    for(int j=0;j<=t.size();j++){
      output[i][j] = -1;
    }
  }
  return minChanges(s,t,output);
}



int main(){
  string s,t;
  cin>>s>>t;

  int n = minChanges(s,t);
  cout << n << endl;
}