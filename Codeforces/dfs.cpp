#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dfs(ll v, ll w, map<ll, vector<ll>>&adj){
    if(adj.find(v)==adj.end()) return w;
    
    if(w%adj[v].size()==0){
        ll ans=0;

        for(auto i:adj[v]){
            ans+=dfs(i, w/adj[v].size(), adj);
        }
        return ans;
    }
    else{
        return 0;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    map<ll, vector<ll>> adj;
    for(int i=0; i<n-1; i++){
        ll a;
        cin>>a;
        adj[a].push_back(i+2);
    }
    ll q;
    cin>>q;

    while(q--){
        ll v, w;
        cin>>v>>w;

        ll ans=w-dfs(v, w, adj);
        cout<<ans<<"\n";
    }
}