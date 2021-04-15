#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
    int n, m;
    cin>>n>>m;

    map<int, vector<int>> adj;
    for(int i=0; i<m; i++){
        int src, des, wt;
        cin>>src>>des>>wt;

        adj[i].push_back(src);
        adj[i].push_back(des);
        adj[i].push_back(wt);
    }
    vector<int> dis(n+1, INF);
    dis[1]=0;
    for(int j=0; j<n-1; j++){
        int i=0;
        while(adj[i].size()!=0){
            if(dis[adj[i][0]]+adj[i][2]<dis[adj[i][1]])
              dis[adj[i][1]]=dis[adj[i][0]]+adj[i][2];

              i++;
        }
    }
    for(int i=2; i<=n; i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
}