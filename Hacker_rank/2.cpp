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
pair<int, pi> edge[100010];
int par[100010];
int sz[100010];

int find(int x){
    while(x!=par[x]) x=par[x];
    return x;
}

void unite(int x, int y){
    x=find(x);
    y=find(y);

    if(sz[x]<sz[y]) swap(x, y);
    sz[x]+=sz[y];

    par[y]=x;
}

int mst(int n){

    int sum=0;

    for(int i=0; i<n; i++){
        int a=edge[i].second.first;
        int b=edge[i].second.second;
        int w=edge[i].first;

        if(find(a)!=find(b)){
            unite(a, b);
            sum+=w;
        }
    }

    return sum;
}
void solve(){
     int n, m;
     cin>>n>>m;
     
     for(int i=0; i<=n; i++){
         par[i]=i;
         sz[i]=1;
     }
     
     for(int i=0; i<m; i++){
         int src, des, w;
         cin>>src>>des>>w;

         edge[i]=make_pair(w, make_pair(src, des));

     }
     sort(edge, edge+m);

     int ans=mst(m);
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
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}