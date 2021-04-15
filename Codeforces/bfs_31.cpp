#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n, m, src, des;
    cin>>n>>m>>src>>des;
    
    ll fun[n+1];
    fun[0]=0;

    for(ll i=1; i<=n; i++) cin>>fun[i];
    unordered_map<ll, vector<ll>> adj;
    for(ll i=0; i<m; i++){
        ll src, des;
        cin>>src>>des;

       // adj[i].push_back((src));
        adj[src].push_back((des));
    }

    vector<ll> dis(n+1, 0);
    vector<ll> vis(n+1, 0);

    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(-fun[src], src));
    dis[src]=-fun[src];
   // fun[src]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();

        ll node=p.second;
        ll wt=p.first;

      if(vis[node]) continue;
      vis[node]=1;

        for(auto i:adj[node]){
            ll ndis=dis[node]-fun[i];
            //cout<<ndis<<" ";
            if(dis[i]>ndis){
               // vis[node]=1;
               if(vis[i]==0){
                //fun[i]=0;
                dis[i]=ndis;}
                else dis[des]=dis[node];
                pq.push(make_pair(dis[i], i));
            }
        }
    }
    /*dis[src]=-fun[src];
   // fun[src]=0;
   vis[src]=1;
    for(int i=0; i<n-1; i++){
        int j=0;
        while(j<m){
          int src=adj[j][0], des=adj[j][1];
          int ndis=dis[src]-fun[des];
          if(ndis<dis[des]){
              if(vis[i]==0){
                  vis[i]=1;
                  dis[des]=ndis;
              }
              else dis[des]=ndis+fun[des];
          }
          j++;
        }
    }*/
    ll ans=-(dis[des]);
    cout<<ans<<"\n";
}