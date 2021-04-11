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
int prime[5000050];
vector<int> arr;
void sieve(){
    for(int i=2; i<5000050; i++) prime[i]=i;
    prime[1]=0;
    prime[0]=0;

    for(int i=2; i*i<5000050; i++){
        if(prime[i]==i){
            for(int j=2*i; j<5000050; j+=i){
                if(prime[j]==j) prime[j]=i;
            }
        }
    }
    arr.push_back(2);
    for(int i=2; i<5000050; i++){
        if(prime[i]==i && i%4==1){
            arr.push_back(i);
        }
    }
}
int dp[100000][10];
int coin(int sum, int k){
    if(sum==0) return 1;
    if(sum<0) return 0;
    if(k<=0) return 0;
    if(dp[sum][k]!=-1) return dp[sum][k];
    return dp[sum][k]=coin(sum-k, k)+coin(sum, k-1);
}

void solve(){
     int n, k;
     cin>>n>>k;
     
     int mx_sum=arr[n-1];
     memset(dp, -1, sizeof(dp));
    int ans=coin(mx_sum, k);
    /* int dp[k+1][mx_sum+1];
     memset(dp, 0, sizeof(dp));
     dp[0][0]=1;
     for(int i=1; i<=k; i++){
         for(int j=0; j<=mx_sum; j++){
             if(j<i) dp[i][j]=dp[i-1][j];
             else dp[i][j]=dp[i-1][j]+dp[i][j-i];
         }
     }
     int ans=dp[k][mx_sum];*/
     cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
