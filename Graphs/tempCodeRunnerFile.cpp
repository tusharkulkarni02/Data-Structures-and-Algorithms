#include<bits/stdc++.h>
using namespace std;


void BFS(int **edges, int startVertex, int n, int e){
  if(n==0) return;
  // if(e==0){
  //   for(int i=0;i<n;i++){
  //     cout << i << " ";
  //   }
  //   return;
  // }
  bool *visited = new bool[n];
  for(int i=0;i<n;i++){
    visited[i] = false;
  }
  
  queue<int> pendingQueue;
  pendingQueue.push(startVertex);
  visited[startVertex] = true;
  while(!pendingQueue.empty()){
    int currVertex = pendingQueue.front();
    cout << currVertex << " ";
    pendingQueue.pop();
    for(int i=0;i<n;i++){
      if(i==currVertex) continue;
      if(edges[currVertex][i] = 1 && !visited[i]){
        pendingQueue.push(i);
        visited[i] = true;
      }
    }
  }
}


int main(){

  int n;
  cin>>n;
 
  int e;
  cin>>e;

  int **edges = new int*[n];
  for(int i=0;i<n;i++){
    edges[i] = new int[n];
    for(int j=0;j<n;j++){
      edges[i][j] = 0;
    }
  }

  for(int i=0;i<e;i++){
    int f,s;cin>>f>>s;
    edges[f][s] = edges[s][f] = 1;
  }

  
  BFS(edges,0,n,e);

}