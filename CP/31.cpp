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
void solve(){
     int n, m;
     cin>>n>>m;
     
     int degree[n+1]={0};
     unordered_map<int, set<int>> edge;
     vector<pi> sib;

     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         edge[a].insert(b);
         edge[b].insert(a);
         sib.pb({a, b});
         degree[a]++;
         degree[b]++;
     }
     
     int ans=inf;
     for(int j=0; j<m; j++){
         int a=sib[j].ff;
         int b=sib[j].ss;
     for(int i=1; i<=n; i++){
         if(edge[i].size()==0) continue;
         if(edge[i].find(a)!=edge[i].end() && edge[i].find(b)!=edge[i].end()){
             int rec=degree[i]+degree[a]+degree[b]-6;
             ans=min(ans, rec);
         }
     }
     }
     if(ans==inf) ans=-1;
     cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
  //  cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}