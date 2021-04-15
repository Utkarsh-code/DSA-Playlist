#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll w, n;
    cin>>n>>w;

    ll val[n], wt[n];
    for(ll i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }

    /*ll dp[2][w+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0]=0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i%2==0){
                if(j<wt[i-1]) dp[0][j]=dp[1][j];
                else dp[0][j]=max(dp[1][j], dp[1][j-wt[i-1]]+val[i-1]);
            }
            else{
                if(j<wt[i-1]) dp[1][j]=dp[0][j];
                else dp[1][j]=max(dp[0][j], dp[0][j-wt[i-1]]+val[i-1]);
            }
        }
    }

    if(n%2==0) cout<<dp[0][w]<<"\n";
    else cout<<dp[1][w]<<"\n";*/
    //cout<<"0\n";
    ll dp[w+1];
    //cout<<"0 ";
    memset(dp, 0, sizeof(dp));
    dp[0]=0;

    for(ll i=0; i<n; i++){
        //cout<<"2"<<" ";
        for(ll j=w; j>=wt[i]; j--){
           // cout<<"1"<<" ";
            dp[j]=max(dp[j], dp[j-wt[i]]+val[i]);
        }
    }
    cout<<dp[w]<<"\n";
}