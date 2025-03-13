#include<bits/stdc++.h>
#include<queue>
int front=0;
int rear=0;
int size=0;
int arr[100];
void push(int x){
    if(size==100){
        cout<<"Queue is full"<<endl;
        return;
    }
    arr[rear]=x;
    rear++;
    size++;
}
void pop(){
    if(size==0){
        cout<<"Queue is empty"<<endl;
        return;
    }
    front++;
    size--;
}

using namespace std;
int main(){
    
}