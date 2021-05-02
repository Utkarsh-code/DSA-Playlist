#include<bits/stdc++.h>
using namespace std;

int a[200010];
int segtree[4*200010];
void build_segtree(int node, int st, int end){
     if(st==end){
         segtree[node]=a[st];
         return;
     }
     else{
         int mid=(st+end)/2;
         build_segtree(2*node, st, mid);
         build_segtree(2*node+1, mid+1, end);
         segtree[node]=min(segtree[2*node],segtree[(2*node)+1]);
     }
}

void update_segtree(int node, int st, int end, int idx, int num){
            if(st==end){
               // a[idx]+=num;
               // segtree[node]+=num;
               a[idx]=num;
               segtree[node]=num;
                return;
            }
            else{
                int mid=(st+end)/2;
                if(st<=idx && idx<=mid){
                    update_segtree(2*node, st, mid, idx, num);
                }
                else{
                    update_segtree(2*node+1, mid+1, end, idx, num);
                }
                segtree[node]=min(segtree[2*node],segtree[2*node+1]);
            }
}

int query_segtree(int node, int st, int end, int l, int r){
              if(r<st  || l>end) return INT_MAX;
              if(l<=st && end<=r) return segtree[node];
              
              int mid=(st+end)/2;
              int x=query_segtree(2*node, st, mid, l, r);
              int y=query_segtree(2*node+1, mid+1, end, l, r);
              return min(x, y);

}
int main(){
    int n, query;
    cin>>n>>query;

    
    for(int i=0; i<n; i++) cin>>a[i];
    build_segtree(1, 0, n-1);

    

    while(query--){
           char ch;
           cin>>ch;

           if(ch=='q'){
               // query
               int l, r;
               cin>>l>>r;
               l--;
               r--;

               int ans=query_segtree(1, 0, n-1, l, r);
               cout<<ans<<"\n";

           }
           else{
               // update
               int idx, num;
               cin>>idx>>num;
               idx--;
               update_segtree(1, 0, n-1, idx, num);
           }
    }
}