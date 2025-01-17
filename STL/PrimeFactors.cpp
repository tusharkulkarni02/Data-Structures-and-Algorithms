#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<int> prime(N,1);
vector<int> lp(N,0); // lowestprime factor for every no.

int main(){
  prime[0]=prime[1]=0;
  for(int i=2;i<N;i++)
  {
    if(prime[i])
    { 
      lp[i] = i;
      for(int j=2*i;j<N;j+=i)
      {
        prime[j]=0;
        if(lp[j]==0){
          lp[j]=i;
        }
      }
    }
  }

  int num;
  cin>>num;
  
  int lowestprimefactor = lp[num];
  unordered_map<int,int> primefactors;
  while(num>1){
    primefactors[lowestprimefactor]++;;
    num/=lowestprimefactor;
    lowestprimefactor = lp[num];
  }
  for(auto &i:primefactors){
    cout << i.first << ' ' << i.second << endl;
  }
}