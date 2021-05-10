#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define ff first
#define ss second
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
pii edge[200010];
int par[100010];
int sz[100010];
int n, m;
int id(int x){

    while(x!=par[x]){
       // par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
void unite(int x, int y){
    int a=id(x);
    int b=id(y);
    if(sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b];
    par[b]=a;
}
int mst(){
    int mncost=0;

    for(int i=0; i<m; i++){
          int a=edge[i].ss.ff;
          int b=edge[i].ss.ss;
          int cost=edge[i].ff;

          if(id(a)!=id(b)){
              unite(a, b);
              mncost+=cost;
          }
    }
    return mncost;
}

void solve(){
    
    cin>>n>>m;
    for(int i=1; i<100005; i++){ par[i]=i; sz[i]=1;}
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        edge[i]={w, {a, b}};
    }
    sort(edge, edge+m);
    int ans=mst();


    int  s=0;
    for(int i=1; i<=n; i++){ //cout<<par[i]<<" ";
       if(par[i]==i) s++;}
       
       if(s>1){
           cout<<"IMPOSSIBLE\n";
           return;
       }

    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
