#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll max_n = 1e6 + 9;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

ll prime[max_n];
ll num[max_n];

void sieve(){
     for(int i=2; i<max_n; i++){
          prime[i]=i;
     }
        prime[0]=inf;
        prime[1]=0;
     for(int i=2; i*i<max_n; i++){
          if(prime[i]==i){
               for(int j=i*i; j<max_n; j+=i){
                    prime[j]=i;
               }
          }
     }
     ll cnt=0;
     for(int i=0; i<max_n; i++){
          if(prime[i]==i) cnt++;
          num[i]=cnt;
     }
}
int main(){
    sieve();
    ll t;
    cin>>t;

    while(t--){
        ll x, y;
        cin>>x>>y;

        ll ans=num[x];
        if(ans<=y){
            cout<<"Chef\n";
        }
        else{
            cout<<"Divyam\n";
        }
    }
}