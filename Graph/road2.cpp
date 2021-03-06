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
vector<int> ans;

bool dfs(int src, int vis[], int rec[]){
    
    vis[src]=1;
    rec[src]=1;
    for(int x:edge[src]){
        if(!vis[x]){
            if(dfs(x, vis, rec)){
                ans.push_back(x);
                return true;
            }
        }
        else if(rec[x]){
            ans.push_back(x);
           // ans.push_back(src);
            return true;
        }
    }
    rec[src]=0;
    return false;
}
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
    }

    int vis[n+1]={0};
    int rec[n+1]={0};
    int fl=0;
    for(int i=1; i<=n; i++){
          if(!vis[i]){
            if(dfs(i, vis, rec)){
                ans.push_back(i);
                fl=1;
                break;
            }
          } 
          
    }
    if(!fl){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int> res;
    int node=ans[0];
    for(int i=0; i<ans.size(); i++){
        if(i==0){
            res.push_back(ans[i]);
            continue;
        }
        res.push_back(ans[i]);
        if(ans[i]==node) break;
    }
    cout<<res.size()<<"\n";
    reverse(res.begin(), res.end());
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
   
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
