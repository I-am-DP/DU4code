#include <iostream>
#include <queue>
#include <cstring>
#define MAX_N 100

using namespace std;

class Graph {
private:
    int n;
    int adjList[MAX_N][MAX_N];
public:
    Graph(int n) {
        this->n = n;
        memset(adjList, 0, sizeof(adjList));  // initialize the adjacency list to 0
    }

    void addEdge(int u, int v) {
        adjList[u][v] = adjList[v][u] = 1;  // undirected graph
    }

    void bfs(int start) {
        bool visited[MAX_N] = {false};  // initialize visited array to false
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cout << x << " ";
            for (int i = 1; i <= n; i++) {
                if (adjList[x][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    Graph g(n);
    cout << "Enter edges in u,v format:\n";
    for (int i = 1; i <= e; i++) {
        int u, v;
        cout << "Edge " << i << " from: ";
        cin >> u;
        cout << "Edge " << i << " to: ";
        cin >> v;
        g.addEdge(u, v);
    }
    cout << "BFS Traversal starting from vertex 1: ";
    g.bfs(1);
    cout << endl;
    return 0;
}
