#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(ll v, vector<ll>& vis, unordered_map<ll, vector<ll>> &adj){
    vis[v]=1;

    for(auto i:adj[v]){
        if(!vis[i]) dfs(i, vis, adj);
    }
}
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n, m;
        cin>>n>>m;

        unordered_map<ll, vector<ll>> adj;
        for(ll i=0; i<m; i++){
            ll src, des;
            cin>>src>>des;

            adj[src].push_back(des);
            adj[des].push_back(src);
        }

        vector<ll> vis(n, 0);
        
        ll cnt=0;
        for(ll i=0; i<n; i++){
            if(vis[i]==0){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        cout<<cnt<<"\n";
    }
}