#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<ll, set<ll>> mp;
unordered_map<ll, vector<ll>> adj;
ll n;
ll ans=INT_MAX;
void dfs(ll src){
    vector<ll> dis(n+1, 100000000009);
    dis[0]=0;
    vector<ll> vis(n+1, 0);
    queue<ll> q;
    q.push(src);
    dis[src]=0;

    while(!q.empty()){
        ll x=q.front();
        q.pop();

        if(vis[x]) continue;
        vis[x]=1;

        for(auto i:adj[x]){
            ll ndis=1+dis[x];
            if(dis[i]>ndis){
                dis[i]=ndis;
                q.push(i);
            }
        }
    }
    ll max_h=*max_element(dis.begin(), dis.end());
    mp[max_h].insert(src);
}
int main(){
    //ll n;
    cin>>n;

   // unordered_map<ll, vector<ll>> adj;
    for(ll i=0; i<n-1; i++){
        ll src, des;
        cin>>src>>des;

        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    for(ll i=1; i<=n; i++){
        dfs(i);
    }
    for(auto i:mp){
        ans=min(ans, i.first);
    }
    cout<<mp[ans].size()<<"\n";
}