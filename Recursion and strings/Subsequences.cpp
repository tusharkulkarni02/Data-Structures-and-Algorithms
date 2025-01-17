#include<bits/stdc++.h>
using namespace std;

int subseq(string input, string output[]){
  if(input.empty()){
    output[0]="";
    return 1;
  }

  int smalloutsize=subseq(input.substr(1),output);
  for (int i=0;i<smalloutsize;i++){
    output[i+smalloutsize]=input[0]+output[i];
  }
  return 2*smalloutsize;
}



int main(){
  string input;
  cout << "enter input str:";
  cin >> input;

  string* output = new string[1000];

  int count = subseq(input,output);

  for(int i=0;i<count;i++){
    cout << output[i] << endl;
  }
}