#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>

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
int up[20][200010];
void solve(){
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        int num;
        cin>>num;

        up[0][i]=num;
    }

    for(int i=1; i<20; i++){
       for(int j=1; j<=n; j++){
           up[i][j]=up[i-1][up[i-1][j]];
       }
    }

    while(q--){
        int src, des;
        cin>>src>>des;

       if(src==des){
           cout<<"0\n";
           continue;
       }
       
       int res=inf;
       int st=1, end=n;
       while(st<=end){
           int mid=(st+end)/2;
           int k=mid, ans=src;
           for(int j=0; j<20; j++){
             if(k&(1<<j)) ans=up[j][ans];
           }
       
       if(ans==des){
           res=min(res, mid);
           end=mid-1;
       }
       else st=mid+1;
       }
       
       if(res==inf) res=-1;
       cout<<res<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
