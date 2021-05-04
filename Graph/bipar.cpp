#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

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
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int color[n+1];
    int vis[n+1];
    queue<int> q;
     for(int i=1; i<=n; i++){
        color[i]=1;
        vis[i]=0;
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        vis[i]=1;
        q.push(i);
        color[i]=1;
   
    
    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(int i:edge[x]){
           if(!vis[i]){
               vis[i]=1;
               color[i]=-color[x];
               q.push(i);
           }
           else{
                 if(color[i]==color[x]){
                     cout<<"IMPOSSIBLE\n";
                     return;
                 }
           }
        }
    }
    }
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            cout<<2<<" ";
            continue;

        }
        cout<<1<<" ";
    }
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
