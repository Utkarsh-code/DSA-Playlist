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

int sz=4;
set<int> s;
void fun1(int x, int y){
    x+=y;
    int f=0;
    if(x<0) f=1;
    x=abs(x);
    if(x%2==0){

        if(f) x=-(x/2);
        else x=x/2;

         s.insert(x);
    }
    //else s.insert(mod);
    else sz--;
}
int fun(int x, int y, int k){
       // int x=grid[0][0], y=grid[0][2];
     int z=x+y;
     int fl=0;
     if(z<0) fl=1;

     z=abs(z);
     if((z%2)==0){
        if(fl) z=-(z/2);
        else z=z/2;
        
        if(z==k) return 1;
     }
     return 0;
}
void solve(){

    int grid[3][3];
     for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
              if(i==1 && j==1){
                  grid[i][j]=0;
                  continue;
              }
              cin>>grid[i][j];
         }
     }

     int ans=0;
     ans+=fun(grid[0][0], grid[0][2], grid[0][1]);
     ans+=fun(grid[2][0], grid[2][2], grid[2][1]);
     ans+=fun(grid[0][0], grid[2][0], grid[1][0]);
     ans+=fun(grid[0][2], grid[2][2], grid[1][2]);
     s.clear();
    // cout<<ans<<" ";
     sz=4;
     fun1(grid[0][1], grid[2][1]);
     fun1(grid[1][0], grid[1][2]);
     fun1(grid[0][0], grid[2][2]);
     fun1(grid[0][2], grid[2][0]);
     ans+=(sz-s.size()+1);
     if(sz==0) ans--;
     
     cout<<ans<<"\n";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}