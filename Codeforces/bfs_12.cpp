#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<ll, vector<pair<ll, ll>>> adj;
ll  n;
//vector<ll> dis(500005);
//vector<ll> vis(500005);
pair<ll, ll> bfs(ll v){
    vector<ll> vis(n+1);
    vector<ll> dis(n+1);
    queue<ll> q;
    dis[v]=0;
    q.push(v);
    vis[v]=1;
    while (!q.empty())
    {
        ll p=q.front();
        q.pop();

        for(auto i:adj[p]){
            ll node=i.first;
            ll wt=i.second;

            if(vis[node]==0){
                vis[node]=1;
                dis[node]=wt+dis[p];
                q.push(node);
            }
        }
    }
    ll INF=-100000000;
    ll ans=INF, idx=0;
    for(ll i=1; i<=n; i++){
        //cout<<i<<" ";
       // cout<<dis[i]<<" ";
        if(dis[i]>ans){
            ans=dis[i];
            idx=i;
        }
    } 
    pair<ll, ll> an=make_pair(idx, ans);  
   // cout<<ans<<" " ;
    return an;
}
int main(){
    ll t;
    cin>>t;

    while(t--){
       // ll n;
        cin>>n;
         // cout<<n<<" ";
         adj.clear();
        for(ll i=0; i<n-1; i++){
            ll src, des, wt;
            cin>>src>>des>>wt;

            adj[src].push_back(make_pair(des, wt));
            adj[des].push_back(make_pair(src, wt));
        }

        //dis[1]=0;
       // dis.clear();
        pair<ll, ll> p=bfs(1);
        ll idx=p.first;
        //cout<<idx<<"\n";
       // dis.clear();
        pair<ll, ll> ans=bfs(idx);

        cout<<ans.second<<"\n";
    }
}