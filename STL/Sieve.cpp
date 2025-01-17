#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

vector<int> prime(N, 1);

int main()
{
  prime[0] = prime[1] = 0;
  for(int i=2;i<N;i++)
  {
    if(prime[i]==1)
    {
      for(int j = 2*i;j<N;j+=i)
      {
        prime[j]=0;
      }
    }
  }

  for(int i=0;i<80;i++){
    cout << i << " " << prime[i] << endl;
  }
}