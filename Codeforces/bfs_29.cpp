#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
int dis[110][10010];
int vis[110][10010];
int c, n, m;

void solve(unordered_map<int, vector<iii>> &adj){
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(make_pair(0, make_pair(1, 0)));

    dis[1][0]=0;

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
      // cout<<"ut ";
        int node=p.second.first;
        int cost=p.second.second;
        int d=p.first;
       // vis[node][cost]=1;
        if(vis[node][cost]) continue;
        vis[node][cost]=1;
        for(auto i:adj[node]){
            int len=i.second.first;
           // cout<<len<<" ";
            int cx=i.second.second;
            int next_node=i.first;

            int new_cost=cx+cost;

            if(new_cost<=c){
                //if(!vis[next_node][new_cost]){
                    int ndis=len+d;
                   // cout<<ndis<<" ";
                    if(dis[next_node][new_cost]>ndis){
                        dis[next_node][new_cost]=ndis;

                        pq.push(make_pair(dis[next_node][new_cost], make_pair(next_node, new_cost)));
                    }
                //}
            }
        }
    }
}
int main(){
    int t;
    cin>>t;

    while(t--){
      //  int c, n, m;
        for(int i=0; i<110; i++){
            for(int j=0; j<10010; j++){
                dis[i][j]=1000000009;
                vis[i][j]=0;
            }
        }
        cin>>c>>n>>m;

        unordered_map<int, vector<iii>> adj;

        for(int i=0; i<m; i++){
            int src, des, len, t;
            cin>>src>>des>>len>>t;

            adj[src].push_back(make_pair(des, make_pair(len, t)));
        }
    
    solve(adj);
    
    int ans=1000000009;
    for(int i=0; i<=c; i++){
        if(dis[n][i]<ans) ans=dis[n][i];
      //  cout<<dis[n][i]<<" ";
    }
    if(ans>=1000000009) cout<<"-1\n";
    else cout<<ans<<"\n";
  // cout<<"\n";
    }
}