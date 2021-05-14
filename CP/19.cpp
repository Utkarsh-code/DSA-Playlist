#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, int>
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

int sz[1010];
int id[1010];

int find(int x){
    while(x!=id[x]) x=id[x];
    return x;
}

void unite(int a, int b){
    a=find(a);
    b=find(b);

    if(sz[a]<sz[b]) swap(a, b);

    sz[a]+=sz[b];
    id[b]=a;
}

void solve(){
     int n, m;
     cin>>n>>m;
     map<int, vector<pi>> edge;
     for(int i=0; i<m; i++){
         int a, b, idx;
         cin>>a>>b>>idx;

         edge[a].pb({b, idx});
     }

     int q;
     cin>>q;

     while(q--){
         int a, b;
         cin>>a>>b;

         int ans=0;
        
          
          for(int i=1; i<=m; i++){

                for(int ite=1; ite<=n; ite++){
                id[ite]=ite;
                sz[ite]=0;
              }
              for(int j=1; j<=n; j++){
                  for(pi x:edge[j]){

                       int c=x.ss;
                       int y=x.ff;
                       if(c!=i) continue;
                       
                       if(find(y)!=find(j)) unite(y, j);
                  }
              }
              if(find(a)==find(b)) ans++;
          }
         cout<<ans<<"\n";
     }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}