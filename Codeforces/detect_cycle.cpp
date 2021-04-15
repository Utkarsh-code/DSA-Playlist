#include<bits/stdc++.h>
using namespace std;

bool detect_cycle(int v, map<int, bool>& vis, map<int, bool>& res, map<int, vector<int>>& adj){
    if(!vis[v]){
        vis[v]=true;
        res[v]=true;

        for(int i:adj[v]){
            if(!vis[i] && detect_cycle(i, vis, res, adj)) return true;
            else if(res[i]) return true;
        }
    }
    res[v]=false;
    return false;
}
int main(){
     int n, m;
     cin>>n>>m;

     int edge[m][2];
     for(int i=0; i<m; i++){
         for(int j=0; j<2; j++){
             cin>>edge[i][j];
         }
     }
     map<int, vector<int>> adj;
     map<int, bool> vis;
     map<int, bool> res;

     for(int i=0; i<m; i++){
         int src=edge[i][0];
         int des=edge[i][1];

         adj[src].push_back(des);
     }

     for(int i=1; i<=n; i++){
         vis[i]=false;
         res[i]=false;
     }
     
     int fl=0;
     for(int i=1; i<=n; i++){
         if(!vis[i]){
             if(detect_cycle(i, vis, res, adj)){
                 fl=1;
                 break;
             }
         }
     }
     if(fl==1) cout<<"There exist a cycle in a graph\n";
     else cout<<"Graph is a ADG\n";
}