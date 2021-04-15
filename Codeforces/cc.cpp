#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll arr[n];
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }
        ll ans=n*(n-1)/2;
        cout<<ans<<"\n";
    }
}