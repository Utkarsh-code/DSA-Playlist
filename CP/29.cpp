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
int vis[1010][1010];
int n, m;
char row[1010];
char col[1010];
void dfs(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y]) return;
    vis[x][y]=1;

    if(row[x]=='L') dfs(x, y-1);
    else dfs(x, y+1);

    if(col[y]=='U') dfs(x-1, y);
    else dfs(x+1, y);
}
void solve(){
     
     cin>>n>>m;

    
     string s;
     cin>>s;

     for(int i=0; i<s.length(); i++){
         if(s[i]=='<'){
             row[i]='L';
         }
         else{
             row[i]='R';
         }
     }

     string t;
     cin>>t;

     for(int i=0; i<t.length(); i++){
         if(t[i]=='^'){
             col[i]='U';
         }
         else{
             col[i]='D';
         }
     }
     
     memset(vis, 0, sizeof(vis));
     dfs(0, 0);
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(!vis[i][j]){
                 cout<<"NO\n";
                 return;
             }
         }
     }
     memset(vis, 0, sizeof(vis));
     dfs(n-1, m-1);
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(!vis[i][j]){
                 cout<<"NO\n";
                 return;
             }
         }
     }
    /* for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            memset(vis, 0, sizeof(vis));
            dfs(i, j);

            for(int x=0; x<n; x++){
                for(int y=0; y<m; y++){
                    if(!vis[x][y]){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }
     }*/
    

     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(!vis[i][j]){
           //      cout<<"NO\n";
            //     return;
             }
         }
     }
     cout<<"YES\n";
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