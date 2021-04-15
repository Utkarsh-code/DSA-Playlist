#include<bits/stdc++.h>
using namespace std;
int id[100005];
int parent(int x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void merge(int x, int y){
    int a=parent(x);
    int b=parent(y);
    id[a]=b;
}
int main(){
    int n, m;
    cin>>n>>m;

    
    int cnt=0;
    for(int i=1; i<=100005; i++) id[i]=i;
    while(m--){
        int x, y;
        cin>>x>>y;

        if(parent(x)==parent(y)) cnt++;
        else{
            merge(x, y);
        }
    }
    cout<<cnt<<"\n";
}