#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>

const ll max_n = 1e6 + 1;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

int prime[max_n];
//ll num[max_n];

void sieve(){
     for(ll i=2; i<max_n; i++){
          prime[i]=i;
     }

     for(ll i=2; i*i<max_n; i++){
          if(prime[i]==i){
               for(ll j=2*i; j<max_n; j+=i){
                    prime[j]=i;
               }
          }
     }
    /* int cnt=0;
     for(int i=5; i<max_n; i++){
          if(prime[i]==i && prime[i-2]==(i-2)) cnt++;
          num[i]=cnt;
     }*/
}
void solve(){
    ll n;
    cin>>n;
  
  if(prime[n]==n) cout<<"NO\n";
  else{
        if(prime[n]%2!=0) cout<<"YES\n";
        else cout<<"NO\n";
  }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
   sieve();
   int tc;
   cin>>tc;
   for(int i=1; i<=tc; i++){
     //cout << "Case #" << i  << ": ";
        solve();
   }
}
