#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[100000];
ll mx_candy(ll idx, vector<ll>& arr, int n){
    if(idx>=n) return 0;
    if(dp[idx]!=-1) return dp[idx];
    return dp[idx]=max(mx_candy(idx+1, arr, n), mx_candy(idx+2, arr, n)+arr[idx]);
    
}
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   while(1){

       ll n, m;
       cin>>n>>m;

       if((n+m)==0) break;

       vector<vector<ll>> grid(n, vector<ll> (m ,0));

       for(ll i=0; i<n; i++){
           for(ll j=0; j<m; j++){
               ll num;
               cin>>num;

               grid[i][j]=num;
           }
       }
       
       vector<ll> ans(n);
       for(ll i=0; i<n; i++){
           vector<ll> arr=grid[i];
           //memset(dp, -1, sizeof(dp));
           fill(dp, dp+m, -1);
           ans[i]=mx_candy(0, arr, m);
       }
      // memset(dp, -1, sizeof(dp));
      fill(dp, dp+n, -1);
       ll res=mx_candy(0, ans, n);
       cout<<res<<"\n";
   }
}