#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //solve();
    //ll t;
    //cin>>t;
   // while(t--){
        ll n,m;
        cin>>n>>m;

        ll fun[n+1];
        for(ll i=1; i<=n; i++){
            cin>>fun[i];
        }
        unordered_map<ll, vector<ll>> adj;
        ll indegree[n+1]={0};
        for(ll i=0; i<m; i++){
            ll src, des;
            cin>>src>>des;

            adj[src].push_back((des));
            indegree[des]++;
        }
    vector<ll> dis(n+1, 0);
    queue<ll> q;
    for(ll i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
            dis[i]=fun[i];
        }
    }

    while(!q.empty()){
        ll x=q.front();
        q.pop();

        for(auto i: adj[x]){
            dis[i]=max(dis[i],dis[x]+fun[i]);
            indegree[i]--;

            if(indegree[i]==0) q.push(i);
        }
    }
   ll ans=*max_element(dis.begin(), dis.end());
   cout<<ans<<"\n";
}