#include <bits/stdc++.h>
using namespace std;
#define size 10
int vistied[10] = {0};
int graph[10][10] = {};
queue<int> q1;
void BFS_Traversal(int start)
{

    q1.push(start);
    vistied[start] = 1;
}
int main()
{

    return 0;
}