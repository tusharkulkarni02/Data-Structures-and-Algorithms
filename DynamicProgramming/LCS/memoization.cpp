  #include<bits/stdc++.h>
  using namespace std;


  int longestCommonSubseq(string s, string t, int **output){
    int m = s.size(); // size of the string s
    int n = t.size();// size of the string t
    if(m==0||n==0){ // if any of the strings are zero return 0 
      return 0;
    }

    if(output[m][n]!=-1){ // if the values in the 2D array is not -1
      return output[m][n];// this means it exist and alredy found , return directly
    }

    int ans;// declare ans variable

    if(s[0]==t[0]){ // if the first characters are equal
      ans = 1+longestCommonSubseq(s.substr(1),t.substr(1),output);
    }else{ // if the first characters are not equal
      int a = longestCommonSubseq(s,t.substr(1),output);
      int b = longestCommonSubseq(s.substr(1),t,output);
      int c = longestCommonSubseq(s.substr(1),t.substr(1),output);
      ans = max(a,max(b,c)); // get the max value
    }

    output[m][n] = ans; // store the ans in output location
    return output[m][n]; // return 
  }



  int main(){
  string s;
  string t;
  cin>>s>>t;
    int **output = new int*[s.size()+1]; // creating 2D Dp array
    for(int i = 0;i<s.size()+1;i++){
      output[i] = new int[t.size()+1];// creating columns in the array
    }
    for(int i=0;i<s.size()+1;i++){
      for(int j=0;j<t.size()+1;j++){
        output[i][j] = -1; // initialzing all the values by -1
      }
    }
  cout << longestCommonSubseq(s,t,output) << endl;
  delete output;
  }