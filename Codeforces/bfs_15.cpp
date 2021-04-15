#include<bits/stdc++.h>
using namespace std;
typedef double ll;
int main(){
    while(1){
        ll n, m;
        cin>>n;

       if(n==0) break;
       cin>>m;
       unordered_map<ll, vector<pair<ll, ll>>> adj;
       for(ll i=0; i<m; i++){
           ll src, des, wt;
           cin>>src>>des>>wt;

           ll w=100/wt;
          // cout<<w<<" ";
           adj[src].push_back(make_pair(des, w));
           adj[des].push_back(make_pair(src, w));

       }
       priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
       pq.push(make_pair(1, 1));
       vector<ll> prob(n+1, 1000000009);
       prob[1]=1;
       vector<ll> vis(n+1, true);
       while(!pq.empty()){
           auto p=pq.top();
           pq.pop();

           ll wt=p.first;
           ll node=p.second;
           if(vis[node]) true;
           vis[node]=true;
           for(auto i:adj[node]){
               ll ndist=(i.second)*wt;
               if(prob[i.first]>ndist){
                   prob[i.first]=ndist;
                   pq.push(make_pair(prob[i.first], i.first));
               }
           }
       }
      // cout<<prob[n]<<" ";
       ll ans=(1/prob[n])*100;
       cout <<fixed<< setprecision(6);
       cout<<ans<<" percent"<<"\n";
    }
}