// #include <bits/stdc++.h>
// using namespace std;

// #define size 9

// int minKey(int distance[], bool visited[])
// {
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < size; v++)
//     {
//         if (visited[v] == false && distance[v] < min)
//         {
//             min = distance[v];
//             min_index = v;
//         }
//     }

//     return min_index;
// }

// void printMST(int parent[], int graph[size][size])
// {
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < size; i++)
//     {
//         cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
//     }
// }

// void prim(int graph[size][size])
// {
//     int parent[size];
//     int distance[size];
//     bool visited[size];

//     for (int i = 0; i < size; i++)
//     {
//         distance[i] = INT_MAX;
//         visited[i] = false;
//     }

//     distance[0] = 0;

//     parent[0] = -1;

//     for (int count = 0; count < size - 1; count++)
//     {
//         int u = minKey(distance, visited);

//         visited[u] = true;

//         for (int v = 0; v < size; v++)
//         {
//             if (graph[u][v] != 0 && visited[v] == false && graph[u][v] < distance[v])
//             {
//                 parent[v] = u;
//                 distance[v] = graph[u][v];
//             }
//         }
//     }

//     printMST(parent, graph);
// }

// int main()
// {
//     int graph[size][size] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
//                              {4, 0, 8, 0, 0, 0, 0, 11, 0},
//                              {0, 8, 0, 7, 0, 4, 0, 0, 2},
//                              {0, 0, 7, 0, 9, 14, 0, 0, 0},
//                              {0, 0, 0, 9, 0, 10, 0, 0, 0},
//                              {0, 0, 4, 14, 10, 0, 2, 0, 0},
//                              {0, 0, 0, 0, 0, 2, 0, 1, 6},
//                              {8, 11, 0, 0, 0, 0, 1, 0, 7},
//                              {0, 0, 2, 0, 0, 0, 6, 7, 0}};

//     prim(graph);

//     return 0;
// }




// // #include <bits/stdc++.h>

// // using namespace std;

// // class kruskal
// // {
// // public:
// //     int cities;

// //     vector<pair<int, pair<int, int>>> v;

// //     kruskal(int val)
// //     {
// //         cities = val;
// //     }

// //     void addEdge(int a, int b, int weight)
// //     {

// //         v.push_back(make_pair(weight, make_pair(a, b)));
// //     }

// //     void sortEdges()
// //     {
// //         sort(v.begin(), v.end());
// //     }

// //     int findParent(vector<int> &parent, int vertex)
// //     {
// //         if (parent[vertex] == -1)
// //             return vertex;
// //         return findParent(parent, parent[vertex]);
// //     }

// //     void unionSets(vector<int> &parent, int u, int v)
// //     {
// //         int uSet = findParent(parent, u);
// //         int vSet = findParent(parent, v);
// //         parent[uSet] = vSet;
// //     }

// //     void kruskalMST()
// //     {
// //         vector<int> parent(cities, -1);
// //         vector<pair<int, pair<int, int>>> result;

// //         for (auto edge : v)
// //         {
// //             int weight = edge.first;
// //             int u = edge.second.first;
// //             int v = edge.second.second;

// //             int uSet = findParent(parent, u);
// //             int vSet = findParent(parent, v);

// //             if (uSet != vSet)
// //             {
// //                 result.push_back(edge);
// //                 unionSets(parent, u, v);
// //             }
// //         }
// //     }

// //     void output()
// //     {
// //         cout << "Sorted Edges:" << endl;
// //         for (auto edge : v)
// //         {
// //             int weight = edge.first;
// //             int a = edge.second.first;
// //             int b = edge.second.second;
// //             cout << a << " - " << b << ", Weight: " << weight << endl;
// //         }
// //     }
// // };
// // int main()
// // {
// //     kruskal k(5);

// //     k.addEdge(1, 2, 30);
// //     k.addEdge(0, 1, 10);
// //     k.addEdge(2, 3, 20);

// //     k.sortEdges();
// //     k.kruskalMST();

// //     k.output();

// //     return 0;
// // }

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int source, destination, weight;
};

// Structure to represent a graph
class Graph
{
public:
    int numVertices;
    vector<vector<pair<int, int>>> adjacencyList; // adjacency list representation of the graph

    // Constructor
    Graph(int numVertices) : numVertices(numVertices)
    {
        adjacencyList.resize(numVertices);
    }

    // Add an edge to the graph
    void addEdge(int source, int destination, int weight)
    {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight}); // Undirected graph
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
int primMST(const Graph &graph)
{
    int totalCost = 0;
    vector<bool> visited(graph.numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap

    pq.push({0, 0}); // Start with vertex 0

    while (!pq.empty())
    {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        totalCost += cost;
        visited[u] = true;

        for (const auto &neighbor : graph.adjacencyList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v])
            {
                pq.push({weight, v});
            }
        }
    }

    return totalCost;
}

// Disjoint Set Data Structure
class DisjointSet
{
public:
    vector<int> parent, rank;

    // Constructor
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the parent of a node with path compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union operation
    void Union(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        }
        else if (rank[xRoot] > rank[yRoot])
        {
            parent[yRoot] = xRoot;
        }
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

// Function to compare edges by weight for sorting
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
int kruskalMST(const Graph &graph)
{
    int totalCost = 0;
    int numVertices = graph.numVertices;
    vector<Edge> edges;
    DisjointSet ds(numVertices);

    // Push all edges into a vector
    for (int u = 0; u < numVertices; ++u)
    {
        for (const auto &neighbor : graph.adjacencyList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            edges.push_back({u, v, weight});
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Iterate through sorted edges
    for (const auto &edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        // Check if adding the edge creates a cycle
        if (ds.find(u) != ds.find(v))
        {
            totalCost += weight;
            ds.Union(u, v);
        }
    }

    return totalCost;
}

int main()
{
    // Example usage
    int numVertices = 5;
    Graph graph(numVertices);

    // Adding edges
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // Minimum spanning tree using Prim's algorithm
    int primCost = primMST(graph);
    cout << "Minimum Cost using Prim's algorithm: " << primCost << endl;

    // Minimum spanning tree using Kruskal's algorithm
    int kruskalCost = kruskalMST(graph);
    cout << "Minimum Cost using Kruskal's algorithm: " << kruskalCost << endl;

    return 0;
}
