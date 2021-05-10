#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
int cnt;
int comp=0;
int ans[500010];
void dfs(int v, map<int, vector<int>>&adj, int vis[]){
    vis[v]=1;
    ans[v]=comp;
    cnt++;
    for(auto i:adj[v]){
        if(!vis[i]) dfs(i, adj, vis);
    }
    
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //solve();
    //ll t;
    //cin>>t;
   // while(t--){
        int n, m;
        cin>>n>>m;
        
        map<int, vector<int>> adj;
        for(int i=0; i<m; i++){
            int k;
            cin>>k;

            if(k==0) continue;
            int src;
            cin>>src;
            for(int j=1; j<k; j++){
                int des;
                cin>>des;
                adj[src].push_back(des);
                adj[des].push_back(src);

                src=des;
            }
        }
        int vis[n+1]={0};
        int find[n+1];
        find[0]=0;
        comp=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
               cnt=0;
               comp++;
               dfs(i, adj, vis);
               find[comp]=cnt;
            }
        }

        for(int i=1; i<=n; i++){
            cout<<find[ans[i]]<<" ";
        }
}