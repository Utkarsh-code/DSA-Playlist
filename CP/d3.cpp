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
void solve(){
     int n;
     cin>>n;
     
     int arr[n];
     map<int, set<int>> mp, cnt;
     for(int i=0; i<n; i++){
         cin>>arr[i];
         mp[arr[i]].insert(i);
     }

     sort(arr, arr+n);

     for(int i=0; i<n; i++){
         int val=arr[i];
         
         cnt[val].insert(i);
         continue;
         int x=*(mp[val].begin());
           
           if(abs(x-i)&1){
               cout<<"NO\n";
               return;
           }
           mp[val].erase(mp[val].begin());

         /*for(int j:mp[val]){
              if(abs(i-j)&1){
                  cout<<"NO\n";
                  return;
              }

              mp[val].erase(j);
              break;
         }*/
     }
    // cout<<"YES\n";
    for(auto i:cnt){
        int val=i.first;
        
        int odd=0, even=0;
        for(int i:mp[val]){
            if(i&1) odd++;
            else even++;
        }

        for(int i:cnt[val]){
            if(i&1) odd--;
            else even--;
        }

        if(odd || even){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";



    
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}