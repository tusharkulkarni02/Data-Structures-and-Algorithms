https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTabValue=PROBLEM


#include <bits/stdc++.h> 
int getMinDistVertex(vector<int> &distance, vector<bool> &visited, int v){
    int mini = INT_MAX;
    int vertex = 0;
    for(int i=0;i<v;i++){
        if(!visited[i] && distance[i] < mini){
            vertex = i;
            mini = distance[i];
        }
    }
    return vertex;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,vector<pair<int,int>>> adjList;

    for(int i=0;i<edges;i++){
        int node1 = vec[i][0];
        int node2 = vec[i][1];
        int weight = vec[i][2];

        adjList[node1].push_back({node2,weight});
        adjList[node2].push_back({node1,weight});
    }


    vector<bool> visited(vertices,false);
    vector<int> distance(vertices,INT_MAX);

    distance[source] = 0;
    
    for(int i=0;i<vertices;i++){

        int curr = getMinDistVertex(distance,visited,vertices);

        visited[curr] = true;

        for(auto &edge: adjList[curr]){
            int u = edge.first;
            int dist = edge.second;

            if(!visited[u] && distance[u] > distance[curr] + dist){
                distance[u] = distance[curr] + dist;
            }
        }
    }

    return distance;
}
