#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, pair<int,int>>
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
vector<pi> edge;
int id[200010];
int sz[200010];
int find(int x){

    while(x!=id[x]){
        x=id[x];
    }
    return x;
}

void unite(int x, int y){
    x=find(x);
    y=find(y);

    if(sz[x]<sz[y]) swap(x, y);
    sz[x]+=sz[y];

    id[y]=x;
}
int mst(int x){
    int mncost=0;

    for(int i=0; i<x; i++){
        int cost=edge[i].ff;
        int p=edge[i].ss.ff;
        int q=edge[i].ss.ss;

        if(find(p)!=find(q)){
            mncost+=cost;
            unite(p, q);
        }
    }
    return mncost;
}
void solve(){
     int n, m;
     cin>>n>>m;
     for(int i=1; i<=n; i++){ id[i]=i; sz[i]=1;}
     int val[n+1];
     val[0]=0;
     for(int i=1; i<=n; i++){
         cin>>val[i];
     }

     for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        edge.pb({w, {a, b}});
     }
     
     int idx=-1, mn=inf;
     for(int i=1; i<=n; i++){
         if(val[i]<mn){
             mn=val[i];
             idx=i;
         }
     }
    
     for(int i=1; i<=n; i++){
         if(i==idx) continue;
         edge.pb({mn+val[i], {idx, i}});
     }
     
     sort(edge.begin(), edge.end());
     int x=edge.size();
     int ans=mst(x);
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