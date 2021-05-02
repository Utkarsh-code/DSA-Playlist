#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pii pair<ll, ll>
#define ff first
#define ss second
ll ninf=-1e18;
ll a[100010];
pii segtree[4*100010];
pii combine(pii l, pii r){
    pii ans;
    ans.ff=max(l.ff, r.ff);
    ans.ss=max(min(l.ff, r.ff), max(l.ss, r.ss));
    return ans;
}
void build(ll node, ll st, ll end){
    if(st==end){
        segtree[node]=make_pair(a[st], ninf);
        return;
    }
    else{
        ll mid=(st+end)>>1;
        build(2*node, st, mid);
        build(2*node+1, mid+1, end);
        segtree[node]=combine(segtree[2*node], segtree[2*node+1]);
    }
}
pii query(ll node, ll st, ll end, ll l, ll r){
    if(r<st || end<l) return make_pair(ninf, ninf);
    if(st>=l && end<=r) return segtree[node];

    ll mid=(st+end)>>1;
    pii x=query(2*node, st, mid, l, r);
    pii y=query(2*node+1, mid+1, end, l, r);

    return combine(x, y);
}
void update(ll node, ll st, ll end, ll idx, ll val){
         if(st==end){
             a[st]=val;
             segtree[node]=make_pair(val, ninf);
             return;
         }

         else{
             ll mid=(st+end)>>1;
             if(st<=idx && idx<=mid){
                 update(2*node, st, mid, idx, val);
             }
             else{
                 update(2*node+1, mid+1, end, idx, val);
             }
             segtree[node]=combine(segtree[2*node], segtree[2*node+1]);
         }
}
int main(){

    ll n;
    cin>>n;

    for(ll i=0; i<n; i++) cin>>a[i];
    build(1, 0, n-1);

    ll q;
    cin>>q;

    while(q--){
        char ch;
        cin>>ch;

        if(ch=='Q'){
            ll l, r;
            cin>>l>>r;
            l--;
            r--;
            pii ans=query(1, 0, n-1, l, r);
            cout<<(ans.ff+ans.ss)<<"\n";
        }
        else{
            ll idx, num;
            cin>>idx>>num;
            idx--;
            update(1, 0, n-1, idx, num);
        }
    }
}