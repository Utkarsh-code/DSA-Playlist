#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m;
    cin>>n>>m;
    set<int> s;
    for(int i=0; i<m; i++){
        ll a;
        cin>>a;
        s.insert(a);
    }
    ll dp[n+1]={0};
    dp[0]=1;
    if(s.find(1)==s.end()) dp[1]=1;

    for(int i=2; i<=n; i++){
        if(s.find(i)!=s.end()) continue;
        
        dp[i]=(dp[i-1]+dp[i-2]+mod)%mod;
    }
    cout<<dp[n]<<"\n";
}