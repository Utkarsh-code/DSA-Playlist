#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n, m, k, src, des;
    cin>>n>>m>>k>>src>>des;

    unordered_map<int, vector<pair<int, int>>> adj;
    unordered_map<int, vector<pair<int, int>>> mat;
    for(int i=0; i<m; i++){
        int src, des, wt;
        cin>>src>>des>>wt;

        adj[src].push_back(make_pair(des, wt));
        mat[des].push_back(make_pair(src, wt));
    }
    int ans=1000000009;

       // adj[sr].push_back(make_pair(de, w));
      //  adj[de].push_back(make_pair(sr, w));
    

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    vector<bool> vis(n+1, false);
    vector<int> dis(n+1, 1000000009);
    dis[src]=0;

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();

        int wt=p.first;
        int node=p.second;
        if(vis[node]) continue;
        vis[node]=true;

        for(auto i:adj[node]){
            int ndis=i.second+wt;
            if(dis[i.first]>ndis){
                dis[i.first]=ndis;
                pq.push(make_pair(dis[i.first], i.first));
            }
        }
    }
    
    vector<int> rdis(n+1, 1000000009);
    vector<bool> vi(n+1, false);
    pq.push(make_pair(0, des));
    rdis[des]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        
        int wt=p.first;
        int node=p.second;
        if(vi[node]) continue;
        vi[node]=true;

        for(auto i:mat[node]){
            int ndis=wt+i.second;
            if(rdis[i.first]>ndis){
                rdis[i.first]=ndis;
                pq.push(make_pair(rdis[i.first], i.first));
            }
        }
    }
    ans=dis[des];

    for(int i=0; i<k; i++){
        int sr, de, wt;
        cin>>sr>>de>>wt;

      //  if(dis[sr]!=1000000009 && rdis[de]!=1000000009){
            ans=min(ans, dis[sr]+rdis[de]+wt);
       // }
       // if(dis[de]!=1000000009 && rdis[sr]!=1000000009){
            ans=min(ans, dis[de]+rdis[sr]+wt);
       // }
    }
    if(ans>=1000000009) cout<<"-1\n";
    else cout<<ans<<"\n";
    }
}