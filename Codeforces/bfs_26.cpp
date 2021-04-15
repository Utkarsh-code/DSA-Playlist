#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool valid(ll x, ll y){
    if(x<0 || y<0 || x>=10 || y>=10) return false;
    return true;
}
int main(){
    ll srcx;
    while(cin>>srcx){
        ll srcy, desx, desy;
        cin>>srcy>>desx>>desy;

       //queue<pair<ll, pair<ll, ll>>> pq;
        priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>> , greater<pair<ll, pair<ll,ll>>>> pq;
        pq.push(make_pair(0,make_pair(srcx, srcy)));
        vector<vector<ll>> dis(11, vector<ll>(11, 1000000009));
        vector<vector<ll>> vis(11, vector<ll>(11, 0));
        dis[srcx][srcy]=0;
        ll dx[8]={2, 2, 1,1,-1,-1,-2,-2};
        ll dy[8]={1, -1, 2,-2, 2, -2, -1, 1};
        while(!pq.empty()){
               auto p=pq.top();
               pq.pop();

               ll x=p.second.first;
               ll y=p.second.second;

               if(vis[x][y]) continue;
               vis[x][y]=1;

               for(ll i=0; i<8; i++){
                   ll X=x+dx[i];
                   ll Y=y+dy[i];

                   if(valid(X, Y)){
                       ll ndis=x*X +y*Y +dis[x][y];
                       if(dis[X][Y]>ndis){
                           dis[X][Y]=ndis;
                           pq.push(make_pair(dis[X][Y], make_pair(X, Y)));
                       }
                   }
               }
        }
        if(dis[desx][desy]>=1000000009) cout<<"-1\n";
        else cout<<dis[desx][desy]<<"\n";
    }
}