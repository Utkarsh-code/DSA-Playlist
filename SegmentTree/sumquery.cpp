#include<bits/stdc++.h>
using namespace std;
#define  int long long 


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
int segtree[800001];

void build_segtree(int node, int l, int r, int arr[]){

    if(l==r){
        segtree[node]=arr[l];
    }
    else{
        int mid=(l+r)/2;
        build_segtree(2*node, l, mid, arr);
        build_segtree(2*node+1, mid+1, r, arr);

        segtree[node]=segtree[2*node]+segtree[2*node+1];
    }
}

int sum(int node, int tl, int tr, int l, int r){
    
    if(l>r) return 0;

    if(tl==l && tr==r){
        return segtree[node];
    }
    else{
        int mid=(tl+tr)/2;

        int x=sum(2*node, tl, mid, l, min(mid, r));
        int y=sum(2*node+1, mid+1, tr, max(mid+1, l), r);

        return x+y;
    }
}

void update(int node, int l, int r, int pos, int val){

    if(l==r){
        segtree[node]=val;
    }
    else{
        int mid=(l+r)/2;

        if(pos<=mid) update(2*node, l, mid, pos, val);
        else update(2*node+1, mid+1, r, pos, val);
        segtree[node]=segtree[2*node]+segtree[2*node+1];
    }
}

void solve(){
  
    int n;
    cin>>n;

    int q;
    cin>>q;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    
    build_segtree(1, 0, n-1, arr);
    

    for(int i=0; i<q; i++){
        int t, x, y;
        cin>>t>>x>>y;

        if(t==1){
            x--;
            arr[x]=y;
            update(1, 0, n-1, x, y);
        }
        else{
            x--;
            y--;

            int ans=sum(1, 0, n-1, x, y);
            cout<<ans<<"\n";
        }
    }
         
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;

  //  cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
         cout<<setprecision(10);
         cout<<fixed;
        solve();
    }
    return 0;
}
