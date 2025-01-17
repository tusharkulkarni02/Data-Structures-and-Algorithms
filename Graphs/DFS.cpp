#include<bits/stdc++.h>
using namespace std;


void print(int **edges, int n, int startVertex, bool *visited){
  cout << startVertex << endl;
  visited[startVertex] = true;

  for(int i=0;i<n;i++){
    if(i==startVertex) continue;
    if(edges[startVertex][i]==1){
      if(visited[i]==true) continue;
      print(edges,n,i,visited);
    }
  } 
}

int main(){
  printf("Enter no of vertices:\n");
  int n;
  scanf("%d",&n);
  printf("Enter no of edges\n");
  int e;
  scanf("%d",&e);

  printf("Enter the connected edges:\n");
  
  int **edges = new int*[n];
  for(int i=0;i<n;i++){
    edges[i] = new int[n];
    for(int j=0;j<n;j++){
      edges[i][j] = 0;
    }
  }
  for(int i=0;i<e;i++){
    int f,s;
    scanf("%d %d",&f,&s);
    edges[f][s] = edges[s][f] = 1;
  }

  bool *visited = new bool[n];
  for(int i=0;i<n;i++){
    visited[i] = 0;
  }
  int startVertex = 0;
  print(edges,n,startVertex,visited);
  delete edges;
  delete visited;
}