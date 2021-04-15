#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll INF=1e18;
ll dis[300009];
ll vis[300009];
ll n;
vector<pair<ll, ll>> adj[300009];
void dijkstra(ll src){
    for(ll i=1; i<=n+1; i++){
        dis[i]=INF;
        vis[i]=0;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    dis[src]=0;
    pq.push({0, src});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();

        ll wt=curr.first;
        ll tar=curr.second;

        if(vis[tar]) continue;
        vis[tar]=1;

        for(auto i:adj[tar]){
            ll ndis=dis[tar]+i.second;
            if(ndis<dis[i.first]){
                dis[i.first]=ndis;
                pq.push(make_pair(dis[i.first], i.first));
            }
        }
    }
}
int  main(){
   ll  m, k;
   cin>>n>>m>>k;

   ll arr[n+1];
   arr[0]=0;
   for(ll i=1; i<=n; i++){
       cin>>arr[i];
   }
   //map<ll, vector<pair<ll, ll>>> adj;
   for(ll i=0; i<m; i++){
       ll src, des, wt;
       cin>>src>>des>>wt;

       adj[src].push_back(make_pair(des, wt));
       adj[des].push_back(make_pair(src, wt));
   }
   for(ll i=1; i<=n; i++){
       adj[i].push_back(make_pair(n+1, arr[i]));
       adj[n+1].push_back(make_pair(i, arr[i]));
   }
   while(k--){
       ll src;
       cin>>src;

       dijkstra(src);
       for(ll i=1; i<=n; i++) cout<<dis[i]<<" ";
       cout<<"\n";
   }
}