#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define iii pait<int, pair<int, int>>
ll cost[55][1005];
ll vis[55][1005];
ll tim[55][55];
ll troll[55][55];
ll n, max_t;

void solve(){
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll ,pair<ll, ll>>>> pq;
    pq.push(make_pair(0, make_pair(1, 0)));
    cost[1][0]=0;

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();

        ll node=p.second.first;
        ll node_t=p.second.second;
        ll money=p.first;

       if(vis[node][node_t]) continue;
       vis[node][node_t]=1;

        for(ll i=1; i<=n; i++){
             ll t=tim[node][i];
             ll c=troll[node][i];

             if(t+node_t<=max_t && i!=node){
                 {if(cost[i][node_t+t]>c+cost[node][node_t]){
                   //  vis[i][node_t+t]=1;
                     cost[i][node_t+t]=c+cost[node][node_t];
                      pq.push(make_pair(cost[i][node_t+t], make_pair(i, node_t+t)));
                 }
                 }
             }
        }
    }
}
int main(){



    int t;
    cin>>t;
    while(t--){
       // cost.clear();
       // vis.clear();

        for(ll i=1; i<55; i++){
            for(ll j=1; j<1005; j++){
                cost[i][j]=1<<30;
                vis[i][j]=0;
            }
        }
    //ll n, max_t;
    cin>>n>>max_t;
    if(n==0 && max_t==0) break;

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
        
            cin>>tim[i][j];
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            ll num;
            cin>>num;

            troll[i][j]=num;
        }
    }
   // for(ll i=1; i<=max_t; i++){ cost[1][i]=0;}
  // cout<<"\n";
    solve();
    
    ll ans=(1<<30), idx=-1;
    for(ll i=1; i<=max_t; i++){
        //cout<<cost[j][i]<<" ";
        if(cost[n][i]<ans){
            ans=cost[n][i];
            idx=i;
        }
    
    //cout<<"\n";
    }
    if(idx!=-1)
     cout<<ans<<" "<<idx<<"\n";
   else cout<<"-1\n";
    }
}