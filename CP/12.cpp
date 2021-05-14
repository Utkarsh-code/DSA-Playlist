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
int bfs(int src, int des){
    queue<pi> q;
    q.push({0, src});
    set<int> s;
    while(!q.empty()){
        pi p=q.front();
        q.pop();

        int cnt=p.ff;
        int node=p.ss;
        if(s.find(node)!=s.end()) continue;
        s.insert(node);

        if(node==des) return cnt;
        
        if(node<=(2*des))
        q.push({cnt+1, 2*node});
        if(node>0)
        q.push({cnt+1, node-1});
    }
}
void solve(){
     int n, m;
     cin>>n>>m;

     int ans=bfs(n, m);
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
        solve();
    }
    return 0;
}