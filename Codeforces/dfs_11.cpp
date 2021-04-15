#include<bits/stdc++.h>
using namespace std;
void dfs(int v, bool vis[], map<int, vector<int>>&adj){
    vis[v]=true;

    for(auto i:adj[v]){
        if(!vis[i]) dfs(i, vis, adj);
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    
    bool vis[n+1];
    for(int i=0; i<=n; i++) vis[i]=false;
    
    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int src, dis;
        cin>>src>>dis;

        adj[src].push_back(dis);
        adj[dis].push_back(src);
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, vis, adj);
        }
    }
    int ans=m-(n-cnt);
    cout<<ans<<"\n";
}