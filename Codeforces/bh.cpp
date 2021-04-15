#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n, m;
        cin>>n>>m;
        ll ans=0;

        if(n==m) { cout<<"1\n"; continue;}
        
        while(n>0 && m>0){
            if(n>m){
                n=n-m;
            }
            else m=m-n;

            ans++;
        }
        cout<<ans<<"\n";
    }
}