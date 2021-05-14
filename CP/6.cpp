#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
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
unordered_map<int, vector<int>> edg;
int edge=0, ver=0;

void dfs(int v, int vis[]){
    vis[v]=1;
    ver++;

    for(int i:edg[v]){
        edge++;
        if(!vis[i]) dfs(i, vis);
    }
}
void solve(){
     int n , m;
     cin>>n>>m;

     for(int i=0; i<m; i++){
         int a, b;
         cin>>a>>b;

         edg[a].push_back(b);
         edg[b].push_back(a);
     }
     
     int vis[n+1]={0};
     for(int i=1; i<=n; i++){
         if(!vis[i]){
             edge=0;
             ver=0;
             dfs(i, vis);
             edge=edge/2;
            //cout<<edge<<" ";
            //cout<<ver<<" ";
             if(edge!=(ver*(ver-1))/2){
                 cout<<"NO\n";
                 return;
             }
         }
     }
    cout<<"YES\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}