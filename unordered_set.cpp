#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include<map>

using namespace std;

int main()
{
    pair<int, int> p;
    // p=make_pair(5,3);
    // cout<<p.first<<" "<< p.second<<" ";
    // p=make_pair(4,2);
    // cout<<p.first<<" "<< p.second<<" ";
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(15);
    s.insert(35);
    s.insert(12);
    s.insert(90);
    s.emplace(12);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    unordered_set<int> us;
    us.insert(10);
    us.insert(20);
    us.insert(15);
    us.insert(35);
    us.insert(12);
    us.insert(90);
    us.emplace(12);

    for (auto i : us)
    {
        cout << i << " ";
    }
    cout << endl;

    multiset<int> ms;
    ms.insert(12);
    ms.emplace(10);
    ms.insert(20);
    ms.insert(15);
    ms.insert(23);
    ms.insert(12);
    ms.emplace(10);
    ms.insert(27);
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    unordered_multiset<int> ums;
    ums.insert(12);
    ums.emplace(10);
    ums.insert(20);
    ums.insert(15);
    ums.insert(23);
    ums.insert(12);
    ums.emplace(10);
    ums.insert(27);
    for (auto i : ums)
    {
        cout << i << " ";
    }
    cout << endl;

    map<int,int>m;
    m.insert({12,23});
    m.insert({10,12});
    m.insert({20,78});
    m.insert({15,12});
    m.insert({23,31});
    m.insert({12,54});
    m.insert({10,67});
    m.insert({27,90});

    for( auto a:m){
        cout<<"Key: "<<a.first<<" value: "<<a.second<<" "<<endl;
    }
    cout<<endl;



}