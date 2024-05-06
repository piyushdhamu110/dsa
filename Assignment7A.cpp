// #include <bits/stdc++.h>
// using namespace std;

// struct Edge
// {
//     int source, destination, weight;
// };

// class Graph
// {
// public:
//     int numVertices;
//     vector<vector<pair<int, int>>> adjacencyList; 

//     Graph(int numVertices)
//     {
//         this->numVertices = numVertices;
//         adjacencyList.resize(numVertices);
//     }

//     void addEdge(int source, int destination, int weight)
//     {
//         adjacencyList[source].push_back({destination, weight});
//         adjacencyList[destination].push_back({source, weight});
//     }
// };

// int minKey(int distance[], bool visited[], int size)
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

// void printMST(int parent[], const Graph &graph)
// {
//     int total_cost = 0;
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < graph.numVertices; i++)
//     {
//         cout << parent[i] << " - " << i << " \t" << graph.adjacencyList[i][parent[i]].second << " \n";
//         total_cost += graph.adjacencyList[i][parent[i]].second;
//     }
//     cout << "Total Cost: " << total_cost << endl;
// }

// void prim(const Graph &graph)
// {
//     int parent[graph.numVertices];
//     int distance[graph.numVertices];
//     bool visited[graph.numVertices];

//     for (int i = 0; i < graph.numVertices; i++)
//     {
//         distance[i] = INT_MAX;
//         visited[i] = false;
//     }

//     distance[0] = 0;

//     parent[0] = -1;

//     for (int count = 0; count < graph.numVertices - 1; count++)
//     {
//         int u = minKey(distance, visited, graph.numVertices);

//         visited[u] = true;

//         for (size_t i = 0; i < graph.adjacencyList[u].size(); i++)
//         {
//             int v = graph.adjacencyList[u][i].first;
//             int weight = graph.adjacencyList[u][i].second;

//             if (!visited[v] && weight < distance[v])
//             {
//                 parent[v] = u;
//                 distance[v] = weight;
//             }
//         }
//     }

//     printMST(parent, graph);
// }

// int main()
// {
//     int numVertices = 9;
//     Graph graph(numVertices);

//     graph.addEdge(0, 1, 4);
//     graph.addEdge(0, 7, 8);
//     graph.addEdge(1, 2, 8);
//     graph.addEdge(1, 7, 11);
//     graph.addEdge(2, 3, 7);
//     graph.addEdge(2, 8, 2);
//     graph.addEdge(2, 5, 4);
//     graph.addEdge(3, 4, 9);
//     graph.addEdge(3, 5, 14);
//     graph.addEdge(4, 5, 10);
//     graph.addEdge(5, 6, 2);
//     graph.addEdge(6, 7, 1);
//     graph.addEdge(6, 8, 6);
//     graph.addEdge(7, 8, 7);

//     prim(graph);

//     return 0;
// }

// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[], bool visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])
{

    int parent[V];
    int key[V];

    bool visited[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, visited[i] = false;

    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {

        int u = minKey(key, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && visited[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Driver's code
int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    primMST(graph);

    return 0;
}

