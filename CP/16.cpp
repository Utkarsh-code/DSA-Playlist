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
unordered_map<int, vector<int>> edge;
int vis[100010];
vector<int> ans;


void solve(){
     int n, m;
     cin>>n>>m;

     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }

     memset(vis, 0, sizeof(vis));
     ans.clear();
     
     set<int>s;
     s.insert(1);
     vis[1]=1;
     while(!s.empty()){
         int x=*(s.begin());
         s.erase(s.begin());
         ans.pb(x);

         for(int i:edge[x]){
              if(!vis[i]){
                  vis[i]=1;
                  s.insert(i); //O(logn)
              }
         }
     }

     for(int i=0; i<ans.size(); i++){
         cout<<ans[i]<<" ";
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