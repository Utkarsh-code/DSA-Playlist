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
int dp[100000];
int farida(int idx, int arr[], int n){

    if(idx>=n) return 0;
    if(dp[idx]!=-1) return dp[idx];
    return dp[idx]=max(farida(idx+1, arr, n), farida(idx+2, arr, n)+arr[idx]);
}
void solve(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    fill(dp, dp+n, -1);
    int ans=farida(0, arr, n);
    cout<<ans<<"\n";
        
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        cout << "Case " << i  << ": ";
        solve();
    }
    return 0;
}
