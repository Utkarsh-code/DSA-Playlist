#include<bits/stdc++.h>
using namespace std;
unordered_map<int , vector<int>> edge;
int vis[1000];
void dfs(int src){
    vis[src]=1;

    for(int x:edge[src]){
        if(vis[x]==0) dfs(x);
    }
}
int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int src, des;
        cin>>src>>des;

        edge[src].push_back(des);
    }
    int v=0;
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++){
         if(vis[i]==0){
             dfs(i);
             v=i;
         }
    }
    memset(vis, 0, sizeof(vis));
    dfs(v);
    int fl=0;
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            fl=1;
            break;
        }
    }
    if(fl) cout<<"-1\n";
    else cout<<v<<"\n";
}