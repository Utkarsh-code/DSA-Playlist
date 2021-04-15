#include<bits/stdc++.h>
using namespace std;

void toposort(int v, map<int, bool>& vis, stack<int>& s, map<int, vector<int>> & adj){
    vis[v]=true;

    for(auto i:adj[v]){
        if(!vis[i]) toposort(i,vis, s, adj);
    }
    s.push(v);
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
    map<int,bool> vis;
    for(int i=1; i<=n; i++) vis.insert({i, false});

    for(int i=0; i<m; i++){
        int src=edge[i][0];
        int des=edge[i][1];

        adj[src].push_back(des);
    }
    
    stack<int> mystack;
    for(int i=1; i<=n; i++){
        if(!vis[i]) toposort(i, vis, mystack, adj);
    }

    while(!mystack.empty()){
        cout<<mystack.top()<<" ";
        mystack.pop();
    }
}