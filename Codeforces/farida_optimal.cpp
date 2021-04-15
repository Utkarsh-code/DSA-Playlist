#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        if(n==0) cout<<"0\n";
        else{
            ll dp[n+1];
            dp[0]=0;
            dp[1]=a[0];

            for(int i=1; i<n; i++){
                dp[i+1]=max(dp[i], dp[i-1]+a[i]);
            }
            cout<<dp[n]<<"\n";
        }
    }
}