#include<bits/stdc++.h>
using namespace std;
#define  int long long 


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

int dp[1010][1010];
int plane(int left, int right, int k){
    if(right==0 || k==1) return 1;
    if(dp[right][k]!=-1) return dp[right][k];
    
    return dp[right][k]=(plane(right, left, k-1)+ plane(left+1, right-1, k))%mod;
}
void solve(){
  
         int n, k;
         cin>>n>>k;

         memset(dp, -1, sizeof(dp));
         int ans=plane(0, n, k);
         cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
