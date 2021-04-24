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

void solve(){
    int n, k;
    cin>>n>>k;

    int dp[n+1][k+1][2];
    memset(dp, 0, sizeof(dp));

    dp[1][0][0]=1;
    dp[1][0][1]=1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=k;  j++){
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1]=dp[i-1][j][0];
            if(j-1>=0)
            dp[i][j][1]+=dp[i-1][j-1][1];
        }
    }
         int ans=dp[n][k][0]+dp[n][k][1];
         cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        int num;
        cin>>num;
        //cout << "Case #" << i  << ": ";
        cout<<i<<" ";
        solve();
    }
    return 0;
}
