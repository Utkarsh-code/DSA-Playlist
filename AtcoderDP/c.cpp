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
   int n;
   cin>>n;

   vector<int> val[n];

   for(int i=0; i<n; i++){
       int a, b, c;
       cin>>a>>b>>c;

       val[i]={a, b, c};
   }
    int dp[n+1][4];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=3; j++){
            for(int k=1; k<=3; k++){
                if(k==j) continue;
                dp[i][j]=max(dp[i][j], dp[i-1][k]+val[i-1][j-1]);
            }
        }
    }   
    int ans=*max_element(dp[n], dp[n]+4);
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
        solve();
    }
    return 0;
}
