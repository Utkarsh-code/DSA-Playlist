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
int type[100010];
unordered_map<int, vector<int>> edge;
vector<int> answer;
int subtree[100010];
void dfs(int v, int par){
    subtree[v]=0;

    if(type[v]==1) subtree[v]=1;

    for(int i: edge[v]){
        if(i!=par){
            dfs(i, v);
            subtree[v]+=subtree[i];
        }
    }

    if(subtree[v]==1) answer.pb(v);
}
void solve(){
     int n;
     cin>>n;

     for(int i=0; i<n-1; i++){
         int a, b, x;
         cin>>a>>b>>x;

         edge[a].pb(b);
         edge[b].pb(a);

         if(x==2){
             type[a]=1;
             type[b]=1;
         }
     }
     dfs(1, -1);
     cout<<answer.size()<<"\n";
     for(int i=0; i<answer.size(); i++) cout<<answer[i]<<" ";
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