#include<bits/stdc++.h>
using namespace std;
long long int cnt_v, cnt_e;
void dfs(int v, vector<bool>& vis, map<int, vector<int>>&adj){
    vis[v]=true;
    cnt_v++;
    cnt_e+=adj[v].size();

    for(auto i:adj[v]){
        if(!vis[i]){
            dfs(i, vis, adj);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;

    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int src, des;
        cin>>src>>des;

        adj[src].push_back(des);
        adj[des].push_back(src);

    }

    vector<bool> vis(n+1, false);
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
             cnt_v=0; cnt_e=0;
            dfs(i, vis, adj);
             long long int to=(cnt_v)*(cnt_v-1);
            // cout<<to<<" "<<cnt_e<<" ";
            if(to!=cnt_e) {cnt++; break;}
        }
    }
    if(cnt==1) cout<<"NO\n";
    else cout<<"YES\n";
}