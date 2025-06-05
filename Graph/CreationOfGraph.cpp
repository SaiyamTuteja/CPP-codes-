#include <bits/stdc++.h>
using namespace std;
#define size 10
void PrintAdjacencyMatrix(int adj[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; i++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void PrintAdjacancyList(vector<int> adj[size + 1])
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
}