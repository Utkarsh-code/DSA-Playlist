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

ll prime[max_n];
ll num[max_n];

void sieve(){
     for(int i=2; i<max_n; i++){
          prime[i]=i;
     }

     for(int i=2; i*i<max_n; i++){
          if(prime[i]==i){
               for(int j=i*i; j<max_n; j+=i){
                    prime[j]=i;
               }
          }
     }
    // int cnt=0;
    // for(int i=5; i<max_n; i++){
    //      if(prime[i]==i && prime[i-2]==(i-2)) cnt++;
    //      num[i]=cnt;
    // }
}
void solve(){
    
    int x, y;
    cin>>x>>y;

    string st;
    cin>>st;

    int u=0, d=0, l=0, r=0;
    for(int i=0; i<st.length(); i++){
         if(st[i]=='R') r++;
         if(st[i]=='L') l++;
         if(st[i]=='U') u++;
         if(st[i]=='D') d++;
    }
    if(x>=0 && y>=0){
         if(r>=x && u>=y) cout<<"YES\n";
         else cout<<"NO\n";
         
    }

    if(x<0 && y>=0){
         if(l>=abs(x) && u>=y) cout<<"YES\n";
         else cout<<"NO\n";
        // return;
    }

    if(x>=0 && y<0){
         if(r>=x && d>=abs(y)) cout<<"YES\n";
         else cout<<"NO\n";
        // return;
    }

    if(x<0 && y<0){
         if(l>=abs(x) && d>=abs(y)) cout<<"YES\n";
         else cout<<"NO\n";
         //return;
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
