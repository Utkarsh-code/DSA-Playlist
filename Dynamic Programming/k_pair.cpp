//c++ template for competitive programming
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
//int ans=0;
bool check(vector<int>&arr, int k){
    
    int cnt=0;
   // cout<<arr[0]<<" ";
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
   if(cnt==k) return true;
   return false;
}
void k_pair(int mask, int k, int n, vector<int>&arr){
    
    if(__builtin_popcount(mask)==n){
       // if(check(arr, k)) ans++;
        return;
    }

    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0){
            arr.push_back(i);
            k_pair(mask|(1<<i), k, n, arr);
            arr.pop_back();
        }
    }
    return;
}
int dp[1000][1000];
int dp_kpair(int n, int k, int mx_k){
    if(k==0) return 1;
    if(n==0) return 0;
    if(dp[n][k]!=-1) return dp[n][k];
    int sum=0;
    for(int i=0;  i<n && k-i>=0; i++){
        sum+=dp_kpair(n-1, k-i, mx_k);
    }
    return dp[n][k]=sum;
}
void solve(){
    int n, k;
    cin>>n>>k;
    //ans=0;
    vector<int>arr;
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
   // k_pair(0,k, n, arr);
   memset(dp, -1, sizeof(dp));
    int ans=dp_kpair(n, k, k);
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
