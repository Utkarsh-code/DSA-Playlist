#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n, ex, t;
    cin>>n>>ex>>t;

    int m;
    cin>>m;
    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int src, des, wt;
        cin>>src>>des>>wt;

        adj[i].push_back(des);
        adj[i].push_back(src);
        adj[i].push_back(wt);
    }
    int INF=1e9;
    vector<int> dis(n+1, INF);
    dis[ex]=0;

    for(int i=0; i<n-1; i++){
        int j=0;
        while(j<m){
              int src=adj[j][0];
             // cout<<src<<" ";
              int des=adj[j][1];
              int wt=adj[j][2];

              if(wt+dis[src]<dis[des]){
                  dis[des]=wt+dis[src];
              }
              j++;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
       // cout<<dis[i]<<" ";
        if(dis[i]<=t) cnt++;
    }
    cout<<cnt<<"\n";
}