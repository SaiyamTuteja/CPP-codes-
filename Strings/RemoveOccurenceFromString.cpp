#include<bits/stdc++.h>
using namespace std;
string RemoveOccurence(string &s,string part){
    while(s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());

    }
    return s;
}
int main(){
    string str="daabcbaabcbc";
    string part="abc";
    string ans=RemoveOccurence(str,part);
    cout<<"After Removing the occurence from string the string comes out to be : "<<ans<<" ";
    return 0;
}