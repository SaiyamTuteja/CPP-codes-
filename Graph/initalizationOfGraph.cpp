#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Graph
{
    int v;
    list<int> *l;

public:
    // Making adjacency list
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addNodes(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " : ";
            for (auto neighbours : l[i])
            {
                cout << neighbours << " ";
            }
            cout << endl;
        }
    }
    void bfs()
    {
        queue<int> q;
        vector<bool> visited(v, false);
        q.push(0);
        visited[0] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto v : l[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (auto v : l[u])
        {
            if (!vis[v])
            {

                dfsHelper(v, vis);
            }
        }
    }
    void DFS()
    {
        int src = 0;
        vector<bool> visited(v, false);
        dfsHelper(src, visited);
    }
};
int main()
{
    Graph g(5);
    g.addNodes(0, 1);
    g.addNodes(1, 2);
    g.addNodes(1, 3);
    g.addNodes(2, 4);

    // g.print();
    cout << "BFS IS : ";
    g.bfs();
    cout << "DFS IS : ";
    g.DFS();
    return 0;
}