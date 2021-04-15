#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<ll, vector<ll>> adj;
ll val[100010];
ll n;
ll dfs(ll src, ll d){
       vector<ll> vis(n+1, 0);
       d;
       queue<ll> q;
       q.push(src);
       vector<ll> ans;
       //ans.push_back(src);
       vector<ll> dis(n+1, -1);
       dis[src]=0;
       vis[src]=1;
       while(!q.empty()){
           int x=q.front();
           q.pop();
           if(dis[x]>d) break;
           for(auto i:adj[x]){
               if(!vis[i]){
                   vis[i]=1;
                   dis[i]=1+dis[x];
                   q.push(i);
               }
           }
       }
       ll xo=0;
       for(ll i=1; i<=n; i++){
           if(dis[i]!=-1 && dis[i]<=d) xo^=val[i];
       }
       cout<<xo<<" ";
       return xo;
}
int main(){
    ll  d;
    cin>>n>>d;

    //ll val[n+1];
    for(ll i=1; i<=n; i++) cin>>val[i];

    //unordered_map<ll, vector<ll>>  adj;
    for(ll i=0; i<n-1; i++){
        ll src, des;
        cin>>src>>des;

        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    ll ans=0;
    for(ll i=1; i<=n; i++){
        ans+=dfs(i, d);
    }
    cout<<ans<<"\n";
}