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
int id[200010];
int sz[200010];

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
     int n,m, k;
     cin>>n>>m>>k;
     for(int i=1; i<=n; i++){
         id[i]=i;
         sz[i]=1;
     }
     int a[k];
     for(int i=0; i<k; i++) cin>>a[i];
     
     set<pi> edge;
     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;
         edge.insert({a, b});
         if(find(a)!=find(b)) unite(a, b);
     }
     int mx=0;
     int ans=0;
    for(int spc:a){
        int x=sz[find(spc)];
         mx=max(mx,x);
         ans+=(x)*(x-1)/2;
         n-=x;
    }
    ans-=(mx)*(mx-1)/2;
    n+=mx;
    ans+=(n)*(n-1)/2;
    ans-=m;

    cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}