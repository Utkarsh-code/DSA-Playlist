#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
     ll t;
     cin>>t;
     
     int cnt=1;
     while(cnt<=t){
         ll n;
         cin>>n;

         ll arr[n];
         for(int i=0; i<n; i++){
             cin>>arr[i];
         }

         if(n==0) cout<<"Case "<<cnt<<": "<<"0\n";
         if(n==2 || n==1) cout<<"Case "<<cnt<<": "<<*max_element(arr, arr+n)<<"\n";
         else if(n>=3){
             ll dp[n];
             memset(dp, 0, sizeof(dp));
             dp[0]=arr[0];
             dp[1]=arr[1];
            ll ans=INT_MIN;
            ans=max(ans, max(dp[0], dp[1]));
             for(int i=2; i<n; i++){
                // for(int j=0; j<i-1; j++){
                //     dp[i]=max(dp[i], dp[j]+arr[i]);
                // }
                dp[i]=max((i-3<0 ? 0 :dp[i-3]), dp[i-2])+arr[i];
                ans=max(dp[i], ans);
             }
             cout<<"Case "<<cnt<<": "<<ans<<"\n";
         }
         cnt++;
     }
}