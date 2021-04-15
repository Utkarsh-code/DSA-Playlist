#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    ll dp[n];
    for(int i=0; i<n; i++){
        dp[i]=1;
    }

    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0; j--){
            ll num=arr[i];
            if(num>arr[j]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp, dp+n);
}