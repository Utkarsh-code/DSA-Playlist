#include<bits/stdc++.h>
using namespace std; 
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
    map<int, int> indegree;
    for(int i=0; i<m; i++){
        int src=edge[i][0];
        int des=edge[i][1];

        indegree[des]++;
        adj[src].push_back(des);
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }
    int toposort[n];
    int i=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        toposort[i++]=node;

        for(auto j:adj[node]){
            indegree[j]--;
            if(indegree[j]==0)  q.push(j);
        }
    }
    if(i==n){
        for(int i=0; i<n; i++){
            cout<<toposort[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"There is cycle in a given graph\n";
    }
}