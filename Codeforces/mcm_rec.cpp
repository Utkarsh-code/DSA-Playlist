#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(ll a[], ll i, ll j){
    if(i>=j) return 0;
    ll mn=INT_MAX;
    for(ll k=i; k<j; k++){
        ll temp=solve(a, i, k)+solve(a, k+1, j)+a[i-1]*a[k]*a[j];

        mn=min(mn, temp);
    }
    return mn;
}
int main(){
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll ans=solve(arr, 1, n-1);
    cout<<ans<<"\n";
}