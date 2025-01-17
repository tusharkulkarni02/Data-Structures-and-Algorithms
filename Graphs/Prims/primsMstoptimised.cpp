#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int v, int m, vector<pair<pair<int, int>, int>> &edgeList)
{
    /* -> Received edges list in the function which
        -> converted it to adjacency list using unordered_map
        -> key = vertex1 , value =  pair (vertex2, wt of edge bw v1 and v2)*/

    unordered_map<int, vector<pair<int,int>>> adjList; // v1 = {{v2`,w`},{v2,w}.......}

    for(const auto& edge : edgeList){
        int node1 = edge.first.first;
        int node2 = edge.first.second;
        int wt = edge.second;

        adjList[node1].push_back({node2, wt});
        adjList[node2].push_back({node1, wt});
    }


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // created a min-heap priority queue which contains a track of minimum weight edge and vertex

    vector<int> parent(v,-1);// initialy all parent is -1; i.e no parent exist for all vertex
    vector<bool> visited(v,false);// all vertex unvisited
    vector<int> weight(v,INT_MAX);// all weight of the edges are infinity;

    parent[0] = -1;// parent of 0(source) is -1
    weight[0] = 0;// incoming edge weight to source is 0

    pq.push({0,0}); // {weight,vertex} //  push weight and vertex in priority queue

    while(!pq.empty()){ 

        int currVertex = pq.top().second; // get curr vertex in the priority queue having minimum edge weight
        pq.pop();

        if(visited[currVertex]){
            continue;
        }

        visited[currVertex] = true; // mark the curr vertex as visited i.e we are currently present on this vertex

        for(pair<int,int> &it :adjList[currVertex]){ // traverse to the neighbors of that vertex 
            
            int adjVert = it.first; // get the neighbor vertex in the adj list of the curr vertex
            int edgeWt = it.second; //  get its edged weight from curr vertex to the neighbor

            if(!visited[adjVert] && weight[adjVert] > edgeWt){ 
                // if neighbor is not visited and weight of neighbor is greater 
                // than the edge weight from curr vertex to the neighbor
                weight[adjVert] = edgeWt; // change wt of neighvor to weight of edge from curr vertex to the neighbor
                parent[adjVert] = currVertex; // make curr vertex as parent of neighbor
                pq.push({weight[adjVert],adjVert});// push the weight and neighbor in the priority queue
            }

        }
    }

    vector<pair<pair<int, int>, int>> mstEdges; // build mst 
    for(int i = 2; i <= v; i++){
        if(visited[i] && parent[i] != -1){
            mstEdges.push_back({{min(parent[i], i), max(parent[i], i)}, weight[i]});
        }
    }

    sort(mstEdges.begin(), mstEdges.end());

    return mstEdges;
}
