#include <bits/stdc++.h>
#include <deque>
using namespace std;

void print(deque<int> dq)
{
    for (int num : dq)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    deque<int> dq;
    dq.push_back(10);
    printf("push back \n");
    print(dq);
    dq.push_front(20);
    printf("push front \n");
    print(dq);
    dq.emplace_back(30);
    printf("emplace back \n");
    print(dq);
    dq.emplace_front(1);
    printf("emplace front \n");
    print(dq);
    dq.end();
    printf("end \n");
    print(dq);
    dq.rend();
    printf(" rend \n");
    print(dq);
    dq.begin();
    printf(" begin \n");
    print(dq);
    dq.cbegin();
    printf(" cbegin \n");
    print(dq);
}