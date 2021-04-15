#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[1009][1009];
ll berries(ll i, ll w, ll totalw, vector<ll>& a){
    if(i>=a.size()) return w;
    if(dp[i][w]!=-1) return dp[i][w];

    if(w+a[i]<=totalw){
        int x=berries(i+2, w+a[i], totalw, a);
        int y=berries(i+1, w, totalw, a);
         dp[i][w]=max(x, y);
    }
    else{
        dp[i][w]=berries(i+1, w, totalw, a);
    }
    return dp[i][w];
}
int main(){
    ll t;
    cin>>t;
    
    ll cnt=1;
    while(cnt<=t){
        ll n, w;
        cin>>n>>w;

        vector<ll> a(n);
        for(int i=0; i<n; i++){
            int b;
            cin>>b;
            a[i]=b;
        }

        //if(n==0) cout<<"0\n";
        //else{
            memset(dp, -1, sizeof(dp));
            cout<<"Scenario #"<<cnt<<": "<<berries(0,0,w,a)<<"\n";
            cnt++;
    }
}