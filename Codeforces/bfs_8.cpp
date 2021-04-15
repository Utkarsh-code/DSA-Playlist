#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll n, m;
    cin>>n>>m;

    string st;
    cin>>st;

    vector<ll> indeg(n+1, 0);
  //  map<ll, vector<ll>> adj;
     vector<ll> adj[n+1];
    for(ll i=0; i<m; i++){
        ll src, des;
        cin>>src>>des;
       // src--; des--;
        adj[src].push_back(des);
        indeg[des]++;
    }
    ll cnt=0;
    queue<ll> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<ll> toposort;
    while(!q.empty()){
        cnt++;

        ll x=q.front();
        q.pop();
        toposort.push_back(x);

        for(ll i:adj[x]){
            indeg[i]--;
            if(indeg[i]==0) q.push(i);
        }
    }
    if(cnt<n) {cout<<"-1\n"; return;}
    ll ans=0;
    ll dp[n+1];
    for(char c='a'; c<='z'; c++){
        memset(dp,0, sizeof(dp));

        for(ll x:toposort){
          if(st[x-1]==c) dp[x]+=1;

          for(auto y:adj[x]) dp[y]=max(dp[y], dp[x]);
          ans=max(ans, dp[x]);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tc=1;
    //cin>>tc;

    for(int i=1; i<=tc; i++) solve();
}