// C++ Program to find distance
// between two nodes using LCA
 
#include <bits/stdc++.h>
using namespace std;
 
#define MAX 1000
 
#define log 10 // log2(MAX)
 
// Array to store the level
// of each node
int level[MAX];
 
int lca[MAX][log];
int dist[MAX][log];
 
// Vector to store tree
vector<pair<int, int> > graph[MAX];
 
void addEdge(int u, int v, int cost)
{
    graph[u].push_back({ v, cost });
    graph[v].push_back({ u, cost });
}
 
// Pre-Processing to calculate
// values of lca[][], dist[][]
void dfs(int node, int parent,
         int h, int cost)
{
    // Using recursion formula to
    // calculate the values
    // of lca[][]
    lca[node][0] = parent;
 
    // Storing the level of
    // each node
    level[node] = h;
    if (parent != -1) {
        dist[node][0] = cost;
    }
 
    for (int i = 1; i < log; i++) {
        if (lca[node][i - 1] != -1) {
 
            // Using recursion formula to
            // calculate the values of
            // lca[][] and dist[][]
            lca[node][i]
                = lca[lca[node]
                         [i - 1]]
                     [i - 1];
 
            dist[node][i]
                = dist[node][i - 1]
                  + dist[lca[node][i - 1]]
                        [i - 1];
        }
    }
 
    for (auto i : graph[node]) {
        if (i.first == parent)
            continue;
        dfs(i.first, node,
h + 1, i.second);
    }
}
 
// Function to find the distance
// between given nodes u and v
void findDistance(int u, int v)
{
 
    int ans = 0;
 
    // The node which is present
    // farthest from the root node
    // is taken as v. If u is
    // farther from root node
    // then swap the two
    if (level[u] > level[v])
        swap(u, v);
 
    // Finding the ancestor of v
    // which is at same level as u
    for (int i = log - 1; i >= 0; i--) {
 
        if (lca[v][i] != -1
            && level[lca[v][i]]
                   >= level[u]) {
 
            // Adding distance of node
            // v till its 2^i-th ancestor
            ans += dist[v][i];
            v = lca[v][i];
        }
    }
 
    // If u is the ancestor of v
    // then u is the LCA of u and v
    if (v == u) {
 
        cout << ans << endl;
    }
 
    else {
 
        // Finding the node closest to the
        // root which is not the common
        // ancestor of u and v i.e. a node
        // x such that x is not the common
        // ancestor of u and v but lca[x][0] is
        for (int i = log - 1; i >= 0; i--) {
 
            if (lca[v][i] != lca[u][i]) {
 
                // Adding the distance
                // of v and u to
                // its 2^i-th ancestor
                ans += dist[u][i] + dist[v][i];
 
                v = lca[v][i];
                u = lca[u][i];
            }
        }
 
        // Adding the distance of u and v
        // to its first ancestor
        ans += dist[u][0] + dist[v][0];
 
        cout << ans << endl;
    }
}
 
// Driver Code
int main()
{
 
    // Number of nodes
    int n = 5;
 
    // Add edges with their cost
    addEdge(1, 2, 2);
    addEdge(1, 3, 3);
    addEdge(2, 4, 5);
    addEdge(2, 5, 7);
 
    // Initialising lca and dist values
    // with -1 and 0 respectively
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < log; j++) {
            lca[i][j] = -1;
            dist[i][j] = 0;
        }
    }
 
    // Perform DFS
    dfs(1, -1, 0, 0);
 
    // Query 1: {1, 3}
    findDistance(1, 3);
 
    // Query 2: {2, 3}
    findDistance(2, 3);
 
    // Query 3: {3, 5}
    findDistance(3, 5);
 
    return 0;
}