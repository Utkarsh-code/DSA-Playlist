#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>

const ll max_n = 1e6 + 9;
const ll mod = 1e9 + 7;
const ll inf = 1e9;


void solve(){
    ll n, d;

    cin>>n>>d;

    ll arr[n];
    ll num=0;
    for(ll i=0; i<n; i++){
         cin>>arr[i];
         num=arr[i];

         if(num%d==0) cout<<"YES\n";
         else{
              int cnt=1, fl=0;
              num-=d;
              while(num>0){
                   if(num%10==0){
                        cout<<"YES\n";
                        fl=1;
                        break;
                   }
                   num=arr[i];
                   cnt++;
                  num-=d*cnt;
              }
              if(fl==0) cout<<"NO\n";
         }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  // sieve();
   int tc;
   cin>>tc;
   for(int i=1; i<=tc; i++){
     //cout << "Case #" << i  << ": ";
        solve();
   }
}
