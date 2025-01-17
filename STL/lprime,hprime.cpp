#include<bits/stdc++.h>
using namespace std;

const int N = 400;
vector<int> prime(N,1);
vector<int> lowestprime(N,0);
vector<int> highestprime(N,0);

int main(){
	prime[0]=prime[1]=0;
	
	for(int i=2;i<N;i++)
	{
			if(prime[i]==1)
			{
					lowestprime[i]=highestprime[i]=i;
	
					for(int j = 2*i;j<N;j+=i)
					{
            prime[j] = 0;
						highestprime[j] = i;
						
							if(lowestprime[j]==0)
							{
								lowestprime[j]=i;
							}
		  		}
	  	}
	}
	
  for(int i=0;i<N;i++){
    cout << i << " " << prime[i] << " " << lowestprime[i] << " " << highestprime[i] << endl;
  }
}			