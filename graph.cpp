#include <iostream>
#include <list>

using namespace std;

// directed graph using adjacency list

class Graph
{
    int V; // num of vertices
    list<int> *adj; // array containing adjacency lists
    
    // recursive method used by DFS
    void DFSUtil(int v, bool visited[]);
    
public:
    Graph(int V); // constructor
    
    // add edge to graph
    void addEdge(int v, int w);
    
    // print BFS traversal from a source s
    void BFS(int s);
    
    // print DFS traversal from a source v
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}

void Graph::BFS(int s)
{
    // mark all vertices as not visited
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }
    
    // create a queue for BFS
    list<int> queue;
    
    // mark current node as visted and enqueue it
    visited[s] = true;
    queue.push_back(s);
    
    // i will get all adjacent vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty()) {
        // dequeue a vertex from the queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        // get all adjacent vertices of the dequeued vertex s
        // mark and enqueue unvisited adjacents
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{
    // mark current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    
    // recurse for all vertices reachable from v
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
        if(!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v)
{
    // mark all vertices as not visited
    bool *visited = new bool[V];
    
    for(int i=0; i < V; i++) {
        visited[i] = false;
    }
    
    // call recursive helper to print DFS traversal starting from all vertices one by one
    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
             DFSUtil(v, visited);
        }
    }
}

int main()
{
    // create graph
    Graph g(4);
    
    // add edges
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    
    cout << "following is BFS (starting from vertex 2)\n";
    g.BFS(2);
    
    cout << "following is DFS (starting from vertex 2)\n";
    g.DFS(2);
    
    return 0;
}
