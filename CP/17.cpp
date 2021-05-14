#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, int>
int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;
 
int pown(int x, int y){
    int res=1;
 
    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}
int id[200010];

int find(int x){
    while(x!=id[x]) x=id[x];
    return x;
}

void unite(int x, int y){
    
    x=find(x);
    y=find(y);

    id[y]=x;
}
void solve(){
      int n;
      cin>>n;

      for(int i=0; i<n; i++) id[i]=i;
      unordered_map<char, vector<int>> mp;

      for(int i=0; i<n; i++){
          string s;
          cin>>s;

          for(int j=0; j<s.length(); j++){
              mp[s[j]].pb(i);
          }
      }
       int ans=n;
      for(int i=0; i<26; i++){
          if(mp[i+'a'].size()<=1) continue;

          for(int j=0; j+1<mp[i+'a'].size(); j++){
                int a=mp[i+'a'][j];
                int b=mp[i+'a'][j+1];

                if(find(a)!=find(b)){
                    ans--;
                    unite(a, b);
                }
          }
      }
      cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}