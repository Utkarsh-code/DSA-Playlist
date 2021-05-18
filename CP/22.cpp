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
int subtree[100010];
int n;
int ans=0;

void dfs(int v, int par){

    subtree[v]=1;
    for(int i:edge[v]){
        if(i!=par){
            dfs(i, v);
            subtree[v]+=subtree[i];
        }
    }
    int sz=subtree[v];

    if(sz%2==0 && (n-sz)%2==0 && (n-sz)>=0){
        ans++;
        subtree[v]=0;
        n=n-sz;
    }
}
void solve(){
     
     cin>>n;

     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }
     
     ans=-1;
     dfs(1, -1);
     
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