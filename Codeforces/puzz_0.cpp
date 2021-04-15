#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll GCD(ll a, ll b){
    if(b==0) return a;
    return GCD(b, a%b);
}
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll a, b, c;
        cin>>a>>b>>c;

        if(c>a && c>b) {cout<<"NO\n"; continue;}

        ll gcd=GCD(a, b);

        if(c%gcd) cout<<"NO\n";
        else cout<<"YES\n";
    }
}