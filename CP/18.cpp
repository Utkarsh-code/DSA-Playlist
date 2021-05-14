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
int id[100010];
int sz[100010];

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
     int n, k;
     cin>>n>>k;
     for(int i=1; i<=n; i++){
         id[i]=i;
         sz[i]=1;
     }
     for(int i=0; i<n-1; i++){
         int a, b, c;
         cin>>a>>b>>c;

         if(c==1) continue;

         if(find(a)!=find(b)) unite(a, b);
     }
     int ans=pown(n, k);
     int x=0;
     for(int i=1; i<=n; i++){
         if(id[i]==i){
            int p=sz[i];
            x=(x+pown(p, k)+mod)%mod;
         }
     }
     ans=(ans-x+mod)%mod;
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