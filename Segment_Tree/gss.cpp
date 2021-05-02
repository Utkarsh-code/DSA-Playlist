#include<bits/stdc++.h>
using namespace std;
#define  int long long 


int mod=1e9+7;
int inf=1e18;
int ninf=-1e9;

int pown(int x, int y){
    int res=1;

    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}
int a[500005];
int segtree[4*500005];
void build_segtree(int node, int st, int end){
      if(st==end){
          segtree[node]=a[st];
          return;
      }
      else{
          int mid=st+(end-st)/2;
          build_segtree(2*node, st, mid);
          build_segtree(2*node+1, mid+1, end);
          
          int x=(segtree[2*node]);
          int y=segtree[2*node+1];
          segtree[node]=x^y;
         
      }
}
void update(int node, int st, int end, int idx, int num){
    if(st==end){
        a[idx]=num;
        segtree[node]=num;
        return;
    }

    else{
        int mid=(st+end)/2;
        if(st<=idx && idx<=mid){
              update(2*node, st, mid, idx, num);
        }
        else{
            update(2*node+1, mid+1, end, idx, num);
        }

        segtree[node]=(segtree[2*node]^segtree[2*node+1]);
    }
}
int query(int node, int st, int end, int l,int r){

    if(r<st || l>end) return 0;
   // if(st==end) return a[st];
    if(l<=st && end<=r) return segtree[node];

    int mid=st +(end-st)/2;
    int x=query(2*node, st, mid, l, r);
    int y=query(2*node+1, mid+1, end, l, r);

    return x^y;
}
void solve(){
  int n, q;
  cin>>n>>q;

  for(int i=0; i<n; i++)  cin>>a[i];
  build_segtree(1, 0, n-1);


 // int q;
 // cin>>q;

  while(q--){
     // int x;
     // cin>>x;

     // if(x==2){
      int a, b;
      cin>>a>>b;
      a--;
      b--;
      int ans=query(1, 0, n-1, a, b);
      cout<<ans<<"\n";//}

     /* else{
          int idx, num;
          cin>>idx>>num;
          idx--;
          update(1, 0, n-1, idx, num);
      }*/

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
