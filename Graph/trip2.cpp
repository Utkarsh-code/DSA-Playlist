#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define ff first
#define ss second
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
int vis[100010]={0};
int par[100010]={0};
int n;
int sv=-1, ev=-1;
bool cycle(int src, int p){
    vis[src]=1;
    par[src]=p;

    for(int des:edge[src]){
        if(des==p) continue;
        if(vis[des]){
            sv=des;
            ev=src;
            return true;
        }

        if(!vis[des]){
            if(cycle(des, src)) return true;
        }
    }
    return false;
}
bool vis_all(){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(cycle(i, -1)) return true;
        }
    }
    return false;
}
void solve(){
    int  m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bool x=vis_all();
    if(!x){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    int backnode=ev;
    vector<int> ans;
    ans.push_back(sv);

    while(backnode!=sv){
        ans.push_back(backnode);
        backnode=par[backnode];
    }
    ans.push_back(sv);
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
