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
map<int, vector<int>> mp;
int n;
int mn=inf;
void dfs(int v, int par){
  
   subtree[v]=1;

   for(int i: edge[v]){
       if(i!=par){
           dfs(i, v);
           subtree[v]+=subtree[i];
       }
   }
}
void dfs2(int v, int par){
    
    int mx=0;
    if(par!=-1) mx=n-subtree[v];
    

    for(int i:edge[v]){
        if(i!=par){
            dfs2(i, v);
            mx=max(mx, subtree[i]);
        }
    }
    
   // if(mx!=0){
    mp[mx].pb(v);
    mn=min(mn, mx);//}
}
void solve(){
     
    cin>>n;

    edge.clear();
    mp.clear();
    mn=inf;
    memset(subtree, 0, sizeof(subtree));

     int x=-1, y=-1;
     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;
         x=a; 
         y=b;
         edge[a].pb(b);
         edge[b].pb(a);
     }
     //cout<<"utk ";
     dfs(1, -1);
     dfs2(1, -1);

     if(mp[mn].size()==1){
         cout<<x<<" "<<y<<"\n";
         cout<<x<<" "<<y<<"\n";
         return;
     }

     int c1=mp[mn][0];
     int c2=mp[mn][1];
     
     for(int i:edge[c1]){
         if(i!=c2){
             cout<<c1<<" "<<i<<"\n";
             cout<<c2<<" "<<i<<"\n";
             return;
         }
     }
    
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}