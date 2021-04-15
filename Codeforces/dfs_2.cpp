#include<bits/stdc++.h>
using namespace std;
int dp[100005];
void dfs(int v, map<int, vector<pair<int, int>>>& adj){
   // vis[v]=true;
    dp[v]=0;
    for(auto i:adj[v]){
         {dfs(i.first, adj);
        dp[v]=max(dp[v], dp[i.first]+i.second);}

    }
    cout<<v<<":"<<dp[v]<<" ";
}
int main(){
    int t;
    cin>>t;

    while(t--){
           int n;
           cin>>n;

           map<int, vector<pair<int, int>>> adj;
           for(int i=0; i<n-1; i++){
               int src, dis, w;
               cin>>src>>dis>>w;

               adj[src].push_back({dis, w});
               adj[dis].push_back({src, w});
           }
        bool vis[n+1];
        dfs(1, adj);
        for(int i=1; i<=n; i++) vis[i]=false;

        for(int i=n; i>=1; i--){
           // if(!vis[i]) dfs(i, adj);

            // for(int j=1; j<=n; j++) vis[j]=false;
        }
        for(int i=1; i<=n; i++) vis[i]=false;
        for(int i=1; i<=n; i++){
          //  if(!vis[i]) dfs(i, adj);
        }

       // for(int i=1; i<=n; i++) cout<<dp[i]<<" ";
    }
}