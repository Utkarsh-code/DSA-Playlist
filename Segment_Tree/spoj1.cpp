#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct new_segtree{
    ll sum, pref, suff, ans;
};
ll a[200010];
new_segtree segtree[4*200010];
new_segtree combine(new_segtree l, new_segtree r){
    new_segtree res;
    res.sum=l.sum+r.sum;
    res.pref=max(l.pref, l.sum+r.pref);
    res.suff=max(r.suff, r.sum+l.suff);
    res.ans=max(max(l.ans, r.ans), l.suff+r.pref);
    
    return res;
}
new_segtree fun1(ll val){
    new_segtree res;
    res.sum=val;
    res.pref=res.suff=res.ans=val;
    
    return res;
}
void build(ll node, ll st, ll end){
   // cout<<"utk ";
    if(st==end){
       segtree[node]=fun1(a[st]);
      // cout<<"utk ";
       return;
    }

    else{
        ll mid=(st+end)/2;
        build(2*node, st, mid);
        build(2*node+1, mid+1, end);
        segtree[node]=combine(segtree[2*node], segtree[2*node+1]);
    }
    return;
}
void update(int node, int st, int end, int idx, int num){
    if(st==end){
        a[st]=num;
        segtree[node]=fun1(num);
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
new_segtree query(ll node, ll st, ll end, ll l, ll r){
    if(r<st || l>end) return fun1(-150009); 
    if(l<=st && end<=r) return segtree[node];

    ll mid=(st+end)>>1;
    new_segtree x=query(2*node, st, mid, l, r);
    new_segtree y=query(2*node+1,mid+1, end, l, r);
    return combine(x, y);
   //return max(x, y);
}
int main(){
    ll n;
    cin>>n;

    for(ll i=0; i<n; i++) cin>>a[i];
   // cout<<"utk ";
    build(1, 0, n-1);
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;

        if(x==1){
        ll l, r;
        cin>>l>>r;

        l--;
        r--;
        new_segtree p=query(1, 0, n-1, l, r);
        cout<<p.ans<<"\n";}

        else{
            int idx, num;
            cin>>idx>>num;
            idx--;
            update(1, 0, n-1, idx, num);
        }
    }
}