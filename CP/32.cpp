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
int tin[200010];
int tout[200010];
vector<int> preorder;
int cnt=0;
void dfs(int v, int par){
    preorder.pb(v);
    tin[v]=cnt++;
    
    for(int i:edge[v]){
        if(i==par) continue;
        dfs(i, v);
    }

    //preorder.pb(v);
    tout[v]=cnt-1;
}
void solve(){
     int n, q;
     cin>>n>>q;

     for(int i=2; i<=n; i++){
         int a;
         cin>>a;

         edge[a].pb(i);
         edge[i].pb(a);
     }
     
     cnt=0;
     dfs(1, -1);

     while(q--){
         int node, k;
         cin>>node>>k;

         int pos=tin[node]+k-1;
        // pos--;

         if(pos>=(n)){
             cout<<"-1\n";
             continue;
         }
        // pos--;
         int nxnode=preorder[pos];

         if(tin[node]<=tin[nxnode] && tout[nxnode]<=tout[node]){
             cout<<nxnode<<"\n";
             continue;
         }

         cout<<"-1\n";
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