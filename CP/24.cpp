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
int color[200010];
set<int> s;
void dfs(int v, int par){

    int par_col=color[par];
    int col=color[v];

    int mx=max(par_col, col);
    int mn=min(par_col, col);

    int cnt=1;

    for(int i:edge[v]){
        if(par==i) continue;
        
        if(mn==cnt) cnt++;
        if(mx==cnt) cnt++;

        s.insert(cnt);

        color[i]=cnt++;
        dfs(i, v);
    }

}
void solve(){
     int n;
     cin>>n;
     
     for(int i=0; i<n-1; i++){
         int a, b;
         cin>>a>>b;

         edge[a].pb(b);
         edge[b].pb(a);
     }
    
     color[1]=1;
     int cnt=1;
     s.insert(1);
     for(int i:edge[1]){
            color[i]=color[1]+ (cnt++);
            s.insert(color[i]);
            dfs(i, 1);
     }
     
     cout<<s.size()<<"\n";
     for(int i=1; i<=n; i++) cout<<color[i]<<" ";
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