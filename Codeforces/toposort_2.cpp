#include<bits/stdc++.h>
using namespace std;

void dfs(int v, map<int, bool>&vis, map<int, vector<int>>&adj){
    vis[v]=true;

    for(auto i:adj[v]){
        if(!vis[i]) dfs(i, vis, adj);
    }
}
 
bool detect_cycle_fun(int v, map<int, bool>&vis, map<int, bool>&rec, map<int, vector<int>>& adj){
    if(!vis[v]){
        vis[v]=true;
        rec[v]=true;

        for(auto i: adj[v]){
            if(!vis[i] && detect_cycle_fun(i, vis, rec, adj)) return true;
            else if(rec[i]) return true;
        }
    }
    rec[v]=false;
    return false;
}
bool detect_cycle(map<int, vector<int>>&adj, int n){
    map<int, bool> vis;
    map<int, bool> rec;

    for(int i=1; i<=n; i++){
          vis[i]=false;
          rec[i]=false;

    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(detect_cycle_fun(i, vis, rec, adj)) return true;
        }
    }
    return false;
}
int main(){

    int t;
    cin>>t;
    while(t--){
    int n, m;
    cin>>n>>m;

    int edge[m][2];
    for(int i=0; i<m; i++){
        for(int j=0; j<2; j++){
            cin>>edge[i][j];
        }
    }
    map<int, vector<int> > adjList;
    map<int, int> indegree;
    map<int, bool> vis;

    for(int i=1; i<=n; i++){
        vis[i]=false;
    }
    for(int i=0; i<m; i++){
        int src=edge[i][0];
        int des=edge[i][1];

        adjList[src].push_back(des);
        indegree[des]++;
    }
    if(detect_cycle(adjList, n)) cout<<"0\n";
    else{
        int min_indegree=INT_MAX;
        int nodewith_min_indegree=1;
        for(int i=1; i<=n; i++){
            if(indegree[i]<min_indegree) {min_indegree=indegree[i];
            nodewith_min_indegree=i;}
        }
        dfs(nodewith_min_indegree, vis, adjList);
        int fl=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                fl=1;
                break;
            }
        }
        if(fl==1) cout<<"2\n";
        else cout<<"1\n";
    }
    }
}