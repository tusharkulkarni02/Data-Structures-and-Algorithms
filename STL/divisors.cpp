#include<bits/stdc++.h>
using namespace std;

int const N=1e5;
vector<int>divisors[N];

int main(){

  for(int i=2;i<N;i++){
    for(int j=i;j<N;j+=i){
      divisors[j].push_back(i);
    }
  }

  for(int i=0;i<10;i++){
    for(auto &div:divisors[i]){
      cout << div << " ";
    }
    cout << endl;
  }
}