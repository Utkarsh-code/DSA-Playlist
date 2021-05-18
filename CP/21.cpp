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

int color[100010];
unordered_map<int, vector<int>> edge;
int curr_col;
bool ok=true;

void dfs(int v, int par){
      ok=(ok&(color[v]==curr_col));

      for(int i:edge[v]){
          if(i!=par) //continue;
          dfs(i, v);
      }
}

bool dfs_util(int v){
    
    bool ans=true;
    for(int i:edge[v]){
        ok=true;
        curr_col=color[i];
        dfs(i, v);
        ans=ans&ok;
    }
    return ans;
}
void solve(){
     int n;
     cin>>n;

     for(int i=0; i<n-1; i++){
              int a, b;
              cin>>a>>b;

              edge[a].push_back(b);
              edge[b].push_back(a);
     }

     for(int i=1; i<=n; i++) cin>>color[i];
    
    int node1=-1, node2=-1;

     for(int i=1; i<=n; i++){
         for(int j:edge[i]){
             if(color[j]!=color[i]){
                 node1=i;
                 node2=j;
             }
         }
     }
     if(node1==-1){
         cout<<"YES\n";
         cout<<1<<"\n";
         return;
     }

    if(dfs_util(node1)){
        cout<<"YES\n";
        cout<<node1<<"\n";
        return;
    }

    if(dfs_util(node2)){
        cout<<"YES\n";
        cout<<node2<<"\n";
        return;
    }

    cout<<"NO\n";
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