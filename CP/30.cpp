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
   // cout<<"utk ";
     int n, m;
     cin>>n>>m;
   // cout<<"utk ";
     for(int i=1; i<=n; i++){
        id[i]=i;
        sz[i]=1;
     }
     //cout<<"utk ";
     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         if(find(a)!=find(b)) unite(a, b);
     }
      // cout<<"utk  \n";
      // cout<<find(1)<<" ";
     vector<pi> val(n+1);
     val[0]={inf, ninf};
     for(int i=1; i<=n; i++){
         val[i]={inf, ninf};
     }
     //  cout<<"utk ";
     for(int i=1; i<=n; i++){
         int x=find(i);

         val[x]={min(val[x].first,i), max(val[x].second, i)};
     }
    // cout<<"utk ";
     int ans=0;
     sort(val.begin(), val.end());
     
     int end=-1;
     for(auto i:val){
         int x=i.first;
         int y=i.second;
        if(x==inf) continue;

        if(x<=end) ans++;
        end=max(end, y);

     }
    /* for(int i=1; i<=n; i++){
         int mn=val[i].first;
         int mx=val[i].second;

         if(mn==inf) continue;

         for(int j=mn+1; j<mx; j++){
             if(find(j)!=find(mn)){
                 ans++;
                 unite(j, mn);
             }
         }
     }*/
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