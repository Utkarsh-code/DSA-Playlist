#include<bits/stdc++.h>
using namespace std;
int id[10005];
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
    for(int i=1; i<=10005; i++) id[i]=i;
    int cnt=0;
    while(m--){
        int src, des;
        cin>>src>>des;

        if(parent(src)==parent(des)) cnt++;
        else merge(src,des);
    }
    if(cnt) cout<<"NO\n";
    else cout<<"YES\n";
}