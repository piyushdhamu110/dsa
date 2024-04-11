#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    void input(vector<vector<int>>& adj_mat, int n) {
        int val;
        cout << "Enter adjacency matrix elements: ";
        for (int i = 0; i < n; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                cin >> val;
                row.push_back(val);
            }
            adj_mat.push_back(row);
        }
    }

    void output(vector<vector<int>>& adj_mat, int n) {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj_mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(vector<vector<int>>& adj_mat, int n, int start) {
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(start);

        cout << "Depth First Traversal: ";
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;

                for (int i = 0; i < n; ++i) {
                    if (adj_mat[vertex][i] && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    Graph g;
    vector<vector<int>> adj_mat;

    g.input(adj_mat, n);
    g.output(adj_mat, n);

    int startVertex;
    cout << "Enter starting vertex for DFS: ";
    cin >> startVertex;
    g.DFS(adj_mat, n, startVertex);

    return 0;
}
