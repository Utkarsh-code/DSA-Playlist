#include<bits/stdc++.h>
using namespace std;
#define  int long long 

int max_n=2e5+5;
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
void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}
int mul(int a, int b) {
    return (int) a * b % mod;
}
int a[200010];
int segtree[4*200010];
void build_segtree(int node, int node_low, int node_high){
    if(node_low==node_high){
        segtree[node]=a[node_low];
        return;
    }
    int mid=(node_low+ node_high)/2;
    build_segtree(2*node, node_low, mid);
    build_segtree(2*node+1, mid+1, node_high);
}
void update(int node, int st, int end, int l, int r, int val){
    if(l<=st && end<=r){ segtree[node]+=val;
     return; }
     if(l>end || r<st) return;

     int mid=(st+end)/2;
     update(2*node, st, mid, l, r, val);
     update(2*node+1, mid+1, end, l, r, val);
}
int query(int node, int st, int end, int idx){
    if(st==end){
        return segtree[node];
    }

    else{
        int x=0, y=0;
        int mid=(st+end)/2;
        if(st<=idx && idx<=mid) x=query(2*node, st, mid, idx);
        else y=query(2*node+1, mid+1, end, idx);

        return x+y+segtree[node];
    }
}
void solve(){
       int n, q;
       cin>>n>>q;

       for(int i=0; i<n; i++) cin>>a[i];

       build_segtree(1, 0, n-1);

       while ((q--))
       {
           int type;
           cin>>type;

           if(type==1){
                int l, r, val;
                cin>>l>>r>>val;
                l--;
                r--;
                update(1, 0, n-1, l, r, val);
           }
           else{
               int node;
               cin>>node;
               node--;
               int ans=query(1, 0, n-1, node);
               cout<<ans<<"\n";
           }
       }
         
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
