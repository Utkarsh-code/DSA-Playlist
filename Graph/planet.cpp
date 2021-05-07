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
int LOG=31;
int up[31][200010];
unordered_map<int, vector<int>> edge;

void solve(){
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        int num;
        cin>>num;
        edge[i].push_back(num);
        up[0][i]=num;
    }

    for(int i=1; i<LOG; i++){
        for(int j=1; j<=n; j++){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    while(q--){
        int node, k;
        cin>>node>>k;

         
        int ans=node;
        for(int i=0; i<LOG; i++){
            if(k&(1<<i)) ans=up[i][ans];
        }
        cout<<ans<<"\n";
    }
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
