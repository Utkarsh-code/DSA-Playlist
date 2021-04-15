#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll pr, n, m;
ll id[2009];
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
ll kruskal(pair<ll, pair<ll, ll>> adj[]){
    ll min_cost=0;

    for(ll i=0; i<m; i++){
        ll wt=adj[i].first;
        ll src=adj[i].second.first;
        ll des=adj[i].second.second;

        if(parent(src)!=parent(des)){
            min_cost+=wt;
            merge(src, des);
        }
    }
    return pr*min_cost;
}
int main(){
    ll t;
    cin>>t;

    while(t--){
        for(ll i=0; i<2009; i++) id[i]=i;
       // ll pr;
       // ll n, m;
        cin>>pr>>n>>m;
        pair<ll, pair<ll, ll>> adj[m];
        for(ll i=0; i<m; i++){
            ll src, des, wt;
            cin>>src>>des>>wt;

            adj[i]=make_pair(wt, make_pair(src, des));
        }
        sort(adj, adj+m);
        ll ans=kruskal(adj);
        cout<<ans<<"\n";
    }
}