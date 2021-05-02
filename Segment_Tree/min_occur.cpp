#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define inf 1e9
int max_n=2e5+5;
int a[2000];
pii segtree[4*2000];

pii combine(pii a, pii b){
      if(a.ff>b.ff) return b;
      if(b.ff>a.ff) return a;

      return make_pair(a.ff,b.ss+a.ss);
}

void build_segtree(int node, int st, int end){
    if(st==end){
        segtree[node]=make_pair(a[st], 1);
        return;
    }
    else{
        int mid=(st+end)>>1;
        build_segtree(2*node, st, mid);
        build_segtree(2*node+1, mid+1, end);
        segtree[node]= combine(segtree[2*node], segtree[2*node+1]);
    }
}
void update(int node, int st, int end, int idx, int num){
    if(st==end){
        a[st]=num;
        segtree[node]=make_pair(num, 1);
        return;
    }
    else{
        int mid=(st+end)>>1;
        if(st<=idx && idx<=mid){
            update(2*node, st, mid, idx, num);
        }
        else{
            update(2*node+1, mid+1, end, idx, num);
        }
        segtree[node]=combine(segtree[2*node], segtree[2*node+1]);
    }
}
pii query(int node, int st, int end, int l, int r){
    if(st>r || end<l) return make_pair(inf, 0);
    if(st>=l && end<=r) return segtree[node];

    int mid=(st+end)>>1;
    pii x=query(2*node, st, mid, l, r);
    pii y=query(2*node+1, mid+1, end, l, r);

    return combine(x, y);
}
int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++) cin>>a[i];
    build_segtree(1, 0, n-1);

    int q;
    cin>>q;

    while(q--){
        int x;
        cin>>x;

        if(x==1){
            int idx, num;
            cin>>idx>>num;
            idx--;
            update(1, 0, n-1, idx, num);
        }
        else{
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            pii ans=query(1, 0, n-1, l, r);
            cout<<ans.ff<<" "<<ans.ss<<"\n";
        }
    }
}