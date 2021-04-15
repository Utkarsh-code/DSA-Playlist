#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
     int t;
     cin>>t;

     while(t--){
         int n, m, src, des;
         cin>>n>>m>>src>>des;

         unordered_map<int , vector<pair<int, int>>> adj;
         for(int i=0; i<m; i++){
             int src, des, wt;
             cin>>src>>des>>wt;

             adj[src].push_back(make_pair(des, wt));
             adj[des].push_back(make_pair(src, wt));
         }
         vector<int> dis(n+1, 1000000009);
         vector<bool> vis(n+1, false);
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         pq.push(make_pair(0, src));
         dis[src]=0;
         while(!pq.empty()){
             auto x=pq.top();
             pq.pop();

             int wt=x.first;
             int node=x.second;

             if(vis[node]) continue;
             vis[node]=true;

             for(auto i:adj[node]){
                 int ndis=wt+i.second;
                 if(dis[i.first]>ndis){
                     dis[i.first]=ndis;
                     pq.push(make_pair(dis[i.first], i.first));
                 }
             }
         }
         if(dis[des]==1000000009) cout<<"NONE\n";
         else cout<<dis[des]<<"\n";
     }
}