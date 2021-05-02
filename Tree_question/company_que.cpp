#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pii pair<int, int>
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
#define LOG 18
int n;
unordered_map<int, vector<int>> edge;
int up[200010][LOG];
void binary_lifting(int src){

    for(int x:edge[src]){

        up[x][0]=src;

        for(int i=1; i<LOG; i++){
            up[x][i]=up[ up[x][i-1] ][i-1];
        }
        binary_lifting(x);
    }
}
void solve(){
     int query;
     cin>>n>>query;

     for(int i=2; i<=n; i++){
         int num;
         cin>>num;

         edge[num].push_back(i);
     }
     memset(up, 0, sizeof(up));
     binary_lifting(1);

     
     while(query--){
         int src, k;
         cin>>src>>k;

         int ans=src;

         for(int i=0; i<LOG; i++){
             if(k&(1<<i))
             ans=up[ans][i];
         }
         if(ans==0) ans=-1;
         cout<<ans<<"\n";
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