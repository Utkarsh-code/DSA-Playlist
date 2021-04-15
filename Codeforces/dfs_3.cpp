#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int vis[100005]={0};
void dfs(int v, map<int, vector<int>>& adj, int num, int cat[],int m){
    vis[v]=1;
    
    if(cat[v]==1) num++;
    else num=0;

    if(num>m) return;
    if(num<=m && adj[v].size()==1 && v!=1) cnt++;

    for(auto i:adj[v]){
        if(!vis[i])
        dfs(i,adj, num, cat, m);
    }
}
int main(){
    int n, m;
    cin>>n>>m;

    int cat[n+1];
    cat[0]=-1;
    for(int i=1; i<=n; i++){
        cin>>cat[i];
    }

    map<int, vector<int>> adj;
    for(int i=0; i<n-1; i++){
        int src, dis;
        cin>>src>>dis;
        adj[src].push_back(dis);
        adj[dis].push_back(src);
    }
    //int cnt=0;
    dfs(1,adj, 0, cat, m);
    if(adj[1].size()==0) cnt=0;
    cout<<cnt<<"\n";
}