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
int dp[105][100005];
int a[105];
void solve(){
    int n, k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<=a[0]; i++){
        dp[0][i]=1;
    }

    for(int i=1; i<n; i++){

        int prefix_sum[k+1];
        prefix_sum[0]=dp[i-1][0];

        for(int j=1; j<k+1; j++){
            prefix_sum[j]=(prefix_sum[j-1]+dp[i-1][j])%mod;
        }

        for(int j=0; j<k+1; j++){
            if(j>a[i])
            dp[i][j]=(prefix_sum[j]-prefix_sum[j-a[i]-1])%mod;
            else 
            dp[i][j]=prefix_sum[j];
        }
    }
    int ans=dp[n-1][k];
    cout<<ans<<"\n";    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
         cout<<setprecision(10);
         cout<<fixed;
        solve();
    }
    return 0;
}
