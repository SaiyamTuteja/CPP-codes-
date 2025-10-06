#include <iostream>
#include <vector>
#include <list>
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
};
int main()
{
    Graph g(5);
    g.addNodes(0, 1);
    g.addNodes(1, 2);
    g.addNodes(1, 3);
    g.addNodes(2, 3);
    g.addNodes(2, 4);

    g.print();
    return 0;
}