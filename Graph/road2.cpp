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
int backnode=-1;
int found=0;
void dfs(int src, int vis[], int rec[]){
    
    vis[src]=1;

    for(int x:edge[src]){
        if(!vis[x]) dfs(x, vis, rec);
        else{
            ans.push_back(x);
            ans.push_back(src);
            backnode=x;
            return;
        }
        
        if(backnode!=-1){

            if(found==0){
                ans.push_back(src);
                if(src==backnode) found=1;
            }
            return;
        }
    }
    return;
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
            dfs(i, vis, rec);
              if(found==1){  fl=1;
                 break;}
             else ans.clear();
            }
          
    }
    if(!found){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<ans.size()<<"\n";
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
   
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
