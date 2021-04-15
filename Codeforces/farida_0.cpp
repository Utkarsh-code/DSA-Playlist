#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;

    ll cnt=1;
    while(cnt<=t){
        ll n;
        cin>>n;
       
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        if(n==0) cout<<"Case "<<cnt<<": "<<"0\n";
        else{
        ll dp[n+1];
        dp[0]=0;
        dp[1]=a[0];

        for(int i=2; i<=n; i++){
            dp[i]=max(dp[i-1], dp[i-2]+a[i-1]);
        }
        cout<<"Case "<<cnt<<": "<<dp[n]<<"\n";}
        cnt++;
    }
}