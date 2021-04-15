#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll INF=1e18;
vector<pair<ll, pair<ll,ll>>> adj;
ll arr[300009];
ll  n;
ll id[300009];
 ll parent(ll x){
     while(id[x]!=x){
         id[x]=id[id[x]];
         x=id[x];
     }
     return x;
 }
 void merge(ll x, ll y){
     ll a=parent(x);
     ll b=parent(y);
     id[a]=id[b];
 }
 ll solve(){
    // cout<<"utk";
    ll ans=0;
     for(ll i=0; i<adj.size(); i++){
           ll w=adj[i].first;
           ll x=adj[i].second.first;
           ll y=adj[i].second.second;
             
           if(parent(x)!=parent(y)){
               ans+=w;
               merge(x, y);
           }
           //cout<<ans<<" ";
     }
    return ans;
 }
int main(){
   ll  m;
   cin>>n>>m;
   for(ll i=1; i<=n; i++) id[i]=i;
   //ll arr[n+1];
   arr[0]=0;
   for(ll i=1; i<=n; i++) cin>>arr[i];
    
    for(ll i=0; i<m; i++){
       ll src, des, wt;
       cin>>src>>des>>wt;
       
       adj.push_back(make_pair(wt, make_pair(src, des)));
      // adj[i].push_back(src);
      // adj[i].push_back(des);
    }
    ll idx=0, mn=INF;
     for(ll i=1; i<=n; i++){
         if(mn>arr[i]){
           mn=arr[i];
           idx=i;
         }
     }
     // cout<<idx<<" ";
     for(ll i=1; i<=n; i++){
         if(idx==i) continue;
         else adj.push_back(make_pair(mn+arr[i], make_pair(idx, i)));
     }
     sort(adj.begin(), adj.end());
     //cout<<ans<<"\n";
    ll ans=solve();
    cout<<ans<<"\n";
}