#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
using namespace std;

/*
  NOTE: since i was dealing with dense graph , i had to make use adjacency matrix as 
  it quick finds out if there is a edge present b/w two vertices of not
  
  Note : If i had to quickly find the neighbors of any vertex then adjacency list is useful
 */
void dijkstras(vector<vector<int>> &edgeMat, int v){
    
    // unordered_map<int,vector<pair<int,int>>> adjList;

    // for(int i=0;i<edgeList.size();i++){
    //     int node1 = edgeList[i].first.first;
    //     int node2 = edgeList[i].first.second;
    //     int weight = edgeList[i].second;

    //     adjList[node1].push_back({node2,weight});
    //     adjList[node2].push_back({node1,weight});
    // }


    vector<bool> visited(v,false);// initialise all the vertex as not visited
    vector<int> distance(v,INT_MAX);// initialise distanct from source to all the vertices is infinity

    
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    // make a minheap priority queue to get the shortes distance vertex always in O(log n) time


    distance[0] = 0; // mark the distance of the source vertex as 0
    pq.push({0,0}); // {distance, vertex} // push it into the priority queue

    while(!pq.empty()){ 

        int curr = pq.top().second; // get the curr vertex having shortest distance from source
        pq.pop();

        visited[curr] = true; // mark the curr vertex as visited

        for(int i=0;i<v;i++){ // traverse all the neighbour verteces of the curr vertex

            if(edgeMat[curr][i] && !visited[i] && distance[i] > edgeMat[curr][i] + distance[curr]){
                /*
                if vertex i is neighbour of curr vertex & i is not visited & 
                distance of i from source is greater than the sum of 
                distance of curr from source i.e (distance[curr]) and distance vertex i from curr i.e (edgeMat[curr][i])
                */
                distance[i] = edgeMat[curr][i] + distance[curr];
                pq.push({distance[i],i}); //  push new shortest distance of i and i in the pq
            }
        }
    }

    for(int i=0;i<v;i++){
        cout << i << " " << distance[i] << endl; //  prints the distance of vertex i from source
    }
}

int main() {
    
    int v;cin>>v;
    int e;cin>>e;


    // vector<pair<pair<int,int>,int>> edgeList(e);

    // for(int i=0;i<e;i++){
    //     int v1, v2, weight; cin>>v1>>v2>>weight;
    //     edgeList[i]={{v1,v2},weight};
    // }

    vector<vector<int>> edge(v,vector<int>(v));

    for(int i=0;i<e;i++){
        int v1, v2, weight; cin>>v1>>v2>>weight;
        edge[v1][v2] = weight;
        edge[v2][v1] = weight;
    }


    dijkstras(edge,v);
}