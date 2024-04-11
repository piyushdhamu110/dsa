#include <bits/stdc++.h>

using namespace std;

class kruskal
{
public:
    int cities;

    vector<pair<int, pair<int, int>>> v;

    kruskal(int val)
    {
        cities = val;
    }

    void addEdge(int a, int b, int weight)
    {

        v.push_back(make_pair(weight, make_pair(a, b)));
    }

    void sortEdges()
    {
        sort(v.begin(), v.end());
    }

    int findParent(vector<int> &parent, int vertex)
    {
        if (parent[vertex] == -1)
            return vertex;
        return findParent(parent, parent[vertex]);
    }

    void unionSets(vector<int> &parent, int u, int v)
    {
        int uSet = findParent(parent, u);
        int vSet = findParent(parent, v);
        parent[uSet] = vSet;
    }

    void kruskalMST()
    {
        vector<int> parent(cities, -1);
        vector<pair<int, pair<int, int>>> result;

        for (auto edge : v)
        {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int uSet = findParent(parent, u);
            int vSet = findParent(parent, v);

            if (uSet != vSet)
            {
                result.push_back(edge);
                unionSets(parent, u, v);
            }
        }
    }

    void output()
    {
        cout << "Sorted Edges:" << endl;
        for (auto edge : v)
        {
            int weight = edge.first;
            int a = edge.second.first;
            int b = edge.second.second;
            cout << a << " - " << b << ", Weight: " << weight << endl;
        }
    }
};
int main()
{
    kruskal k(5);

    k.addEdge(1, 2, 30);
    k.addEdge(0, 1, 10);
    k.addEdge(2, 3, 20);

    k.sortEdges();
    k.kruskalMST();

    k.output();

    return 0;
}