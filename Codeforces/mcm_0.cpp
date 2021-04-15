#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[1001][1001];
ll solve(ll a[], ll i, ll j){
      if(i>=j) return 0;

      if(dp[i][j]!=-1) return dp[i][j];
      
      ll mn=INT_MAX;
      for(int k=i; k<j; k++){
          ll temp=solve(a, i, k)+solve(a, k+1, j)+a[i-1]*a[k]*a[j];
          mn=min(mn, temp);
      }
      return dp[i][j]=mn;
}
int main(){
       ll n;
       cin>>n;

       ll arr[n];
       for(int i=0; i<n; i++){
           cin>>arr[i];
       }
       memset(dp, -1, sizeof(dp));
       ll ans=solve(arr, 1, n-1);
       cout<<ans<<"\n";
}