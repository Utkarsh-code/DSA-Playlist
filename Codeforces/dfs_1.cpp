#include<bits/stdc++.h>
using namespace std;
int dp[100005];
void dfs(int v, map<int, vector<int>>& adj, map<int, bool>& vis){
    vis[v]=true;
    dp[v]=0;

    for(auto i:adj[v]){
        if(!vis[i]) dfs(i, adj, vis);

        dp[v]=max(dp[i]+1, dp[v]);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
     
    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int src, dis;
        cin>>src>>dis;

        adj[src].push_back(dis);
    }
    map<int, bool>  vis;
    for(int i=0; i<=n; i++) vis[i]=false;

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i, adj, vis);
    }
    int ans=INT_MIN;
    for(int i=1; i<=n; i++){
        ans=max(ans, dp[i]);
    }
    cout<<ans<<"\n";
}