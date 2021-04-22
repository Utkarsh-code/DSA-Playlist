#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define pii pair<int, pair<int, int>>

int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;

int pown(int x, int y){
    int res=1;

    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}
int ti[1010][1010];
int risk[1010][1010];
int n, t;
auto min_risk(){
     
     int dis[n+1][t+1];
     int vis[n+1][t+1];
     for(int i=0; i<=n; i++){
        for(int j=0; j<=t; j++){
           dis[i][j]=inf;
           vis[i][j]=0;
        }
        
     }
     priority_queue<pii, vector<pii>, greater<pii>> pq;
     pq.push({0, {1, t}});
     dis[1][t]=0;
     while (!pq.empty())
     {
         auto p=pq.top();
         pq.pop();

         int curnode=p.second.first;
         int remtime=p.second.second;
         if(vis[curnode][remtime]) continue;
         vis[curnode][remtime]=1;

         for(int i=1; i<=n; i++){
             if(curnode==i) continue;

             if(remtime>=ti[curnode][i]){
                  int nrisk=risk[curnode][i]+dis[curnode][remtime];
                  if(dis[i][remtime-ti[curnode][i]]>nrisk){
                        dis[i][remtime-ti[curnode][i]]=nrisk;
                        pq.push({nrisk, {i, remtime-ti[curnode][i]}});
                  }
             }

         }
     }
     
     int ans=inf;
     int ans2=-1;
     for(int i=0; i<=t; i++){
         if(ans>dis[n][i]){
             ans=dis[n][i];
             ans2=t-i;
         }
     }

     return  make_pair(ans, ans2);

}
void solve(){
  //int n , t;
  cin>>n>>t;
  //memset(time, 0, sizeof(time));
  for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
          cin>>ti[i][j];
      }
  }
   
  for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
          cin>>risk[i][j];
      }
  }
       auto  ans=min_risk(); 
     //  cout<<ans<<"\n";
     if(ans.first==inf){
         cout<<"-1\n";
     }
    else  cout<<ans.first<<" "<<ans.second<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
