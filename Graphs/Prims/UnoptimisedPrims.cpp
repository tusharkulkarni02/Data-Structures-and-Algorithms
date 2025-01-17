#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int getMinWeightIdx(vector<int> &weight, vector<bool> &visited){ // gives the vertex who has an incomig edge of minimum weight
    int vertex = -1;
    int minwt = INT_MAX;
    for(int i=0;i<weight.size();i++){
        if(!visited[i] && weight[i]<minwt){
            vertex = i;
            minwt = weight[i];
        }
    }
    return vertex;
}

void primsMST(vector<vector<int>> &edges, int v){ // accepts adjacency matrix of edges and no of vertices

    vector<bool> visited(v,false); // initialise all vertex as not visited
    vector<int> weight(v,INT_MAX);//  weight as max infinity
    vector<int> parent(v,-1);// all parents as -1

    weight[0] = 0; // weight of 0 is 0
    parent[0] = -1; // consieder no incoming edge to zero in the minimum spanning tree , thus parent of zero is -1
 
    for(int i=0;i<v;i++){ // traverse on all the vertices

        int currVertex = getMinWeightIdx(weight, visited); // get the currVertex who has minimum incoming edge weight
        visited[currVertex] = true; // mark that currVertex as visited
 
        for(int i=0;i<v;i++){ //  traverse on all the vertices
            if(edges[currVertex][i] && !visited[i]){ //  if currVertex and i are neighbours and i is not  visited
                if(edges[currVertex][i] < weight[i]){ // if weight of edge from currVertex to i is less than the existing weight of incoming edge to i
                    weight[i] = edges[currVertex][i];// change the existing weight of incoming edge of i to edge weight from currVertex to i
                    parent[i] = currVertex;// make currVertex a parent of i
                }
            }
        }
    }
    
    for(int i=0;i<v;i++){ // traverse on all the vertices in the parent array
        if(visited[i] && parent[i]!=-1){ // since 0 will have parent as -1 , as there will be no incoming edges to 0
            cout << min(parent[i],i) << " " << max(parent[i],i) << " " << weight[i] << endl;
        }
    }
}

int main() {
    int v;cin>>v;
    int e; cin>>e;

    vector<vector<int>> edges(v,vector<int>(v,0));

    for(int i=0;i<e;i++){
        int source,dest,weight;
        cin >> source >> dest >> weight;
        edges[source][dest] = weight;
        edges[dest][source] = weight;
    }

    primsMST(edges,v);

}