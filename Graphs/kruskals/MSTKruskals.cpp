#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge{   // edge class to inplement edge list
    public:
    int v1;
    int v2;
    int weight;

    edge (){}
  
    edge(int v1, int v2, int weight){ // edge constructor to directly assign values
        this->v1 = v1;
        this->v2 = v2; 
        this->weight = weight;
    }
};


int findParent(int vertex, vector<int> &parent){  // function helps to find original parent of any vertex/node
    if(vertex==parent[vertex]){ // if parent of vertex is vertex itself
        return vertex;
    }
    
    /*NOTE:
        THE RECURSIVE ASSIGNING OF THE VALUES IS DONE TO AVOID CREATION OF LONG CHAINS IN THE 
        PARENT CHILD CONNECTION
        EVERY VERTEX IS MAPPED TO ITS ORIGINAL PARENT AND NOT TO THE PARENT JUSTABOVE IT
        THIS MAKES THE connection tree flatter

        Example to Illustrate the Problem:
        Imagine this scenario:

        Initially, the parent of each node is itself: parent[i] = i.
        After some unions using parent[root1] = root2, the tree might look like this:
       
        1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

        When you need to find the root of node 7, you will have to traverse this long chain (7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1), which becomes inefficient.
        With path compression, you would flatten this tree and get something like:

        1 -> 7
        2 -> 7
        3 -> 7
        4 -> 7
        5 -> 7
        6 -> 7
        Now every future find operation takes constant time, improving the efficiency of the entire algorithm.
    */
    parent[vertex] = findParent(parent[vertex], parent); // call same function on parent of vertex and get it parent
    // ^^^ -> path compression

    return parent[vertex]; // finally return parent;
}


void unionSets(int root1, int root2, vector<int> &parent, vector<int> &rank){ // function makes connection or Unions two different disjoint sets
    if(rank[root1]>rank[root2]){  // if rank[root1] > rank[root2]
        parent[root2] = root1;
    }else if(rank[root2]>rank[root2]){
        parent[root1] = root2;
    }else{ 
        parent[root2] = root1; // if both have same the make anyone parent of the other
        // increase the rank of parent;
        rank[root1]++;
    }
}

vector<edge> kruskalsMST(vector<edge> &input, int v){  // functions returns MST using kruskal's algo

    vector<edge> output; //  output store edges which will be included in the MST

    sort(input.begin(),input.end(),  // sort acc to the input
        [](edge &a, edge &b){
            return a.weight <= b.weight;
        }
    );

    vector<int> parent(v); // initialise the parent vector which will store who is the parent of whome
    vector<int> rank(v,0); // rank stores heirarchy of the vertex in the tree , more rank parent if prefered to be parent
    // NOTE: ^^^^ the above rank vector helps to optimise the existing infficiently working kruskals 
    for(int i=0;i<v;i++){
        parent[i] = i; //  initially initialise every vertex as parent of itself , consiedering all the components of the graphs are disjoint
    }

    int count = 0; //  count stores the current no. of edges in MST
    int i = 0; // to iterate over the input
  
    while(count < v-1 && i<input.size()){    
        //  count < v-1 (condition for MST i.e no of edges == no. of vertices - 1) 

        edge curr = input[i];

        int root1 = findParent(curr.v1,parent); // find root or (original parent of curr.v1)
        int root2 = findParent(curr.v2,parent); 

        if(root1!=root2){ //  both parents are not equal 
            count++; // add the edge to mst edges count
            output.push_back(curr); //  push the edge to the ouput
            /*
            Using parent[root1] = root2 without considering rank or path compression leads to inefficiency because the trees can become very deep, and the find operations become slow.
            DSU with path compression and union by rank/size ensures that the trees stay flat and balanced, making both find and union operations efficient, leading to a faster and correct Kruskal’s MST implementation. 
            */
            unionSets(root1, root2, parent, rank); // pass the roots of the disjointed graphs to decide who will be the parent of whome
            //parent[root2] = root1;
        }

        i++;
    }

    return output;
    
}

int main() {

    int v;cin>>v;
    int e;cin>>e;

    vector<edge> input;

    for(int i=0;i<e;i++){
        int v1,v2,weight;cin>>v1>>v2>>weight;
        edge p(v1,v2,weight);
        input.push_back(p);
    }

    vector<edge> output = kruskalsMST(input,v);

    for(edge &ed:output){
        if(ed.v1<ed.v2){
            cout << ed.v1 << " " << ed.v2 << " " << ed.weight << endl;
        } else{
            cout << ed.v2 << " " << ed.v1 << " " << ed.weight << endl;
        }
    }
    
}