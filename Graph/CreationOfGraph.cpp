#include <iostream>
#include <vector>
using namespace std;

void PrintAdjacencyMatrix(vector<vector<int>> &adjMatrix, int n)
{
    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



void PrintAdjacencyList(vector<vector<int>> &adjList, int n)
{
    cout << "\nAdjacency List:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int v : adjList[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}




int main()
{
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Create dynamic adjacency matrix and list
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<vector<int>> adjList(n);

    cout << "Enter " << m << " edges (as pairs of vertices u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Add edge to matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // remove for directed graph

        // Add edge to list
        adjList[u].push_back(v);
        adjList[v].push_back(u); // remove for directed graph
    }

    // Print both representations
    PrintAdjacencyMatrix(adjMatrix, n);
    PrintAdjacencyList(adjList, n);

    return 0;
}

/*
Sample Input
        Enter the number of vertices: 4
        Enter the number of edges: 3
        Enter 3 edges (as pairs of vertices u v):
        0 1
        1 2
        2 3
*/