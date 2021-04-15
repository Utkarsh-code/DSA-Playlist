#include<bits/stdc++.h>
using namespace std;
void build_tree(int arr[], int segment_tree[], int low, int high, int pos){
    if(low==high){
        segment_tree[pos]=arr[low]; return;
    }
    int mid=(low+high)/2;
    build_tree(arr, segment_tree, low, mid, 2*pos+1);
    build_tree(arr, segment_tree, mid+1,high, 2*pos+2);
     segment_tree[pos]=segment_tree[2*pos+1]+segment_tree[2*pos+2];
}
int max_sum(int segment_tree[], int x, int y, int low, int high, int pos){
    if(x<=low && y>=high) return segment_tree[pos];
    if(low>high || x>high || y<low) return -150009;
    
    if(low!=high){
    int mid=(low+high)/2;
    int ans1=max_sum(segment_tree,x, y, low, mid, 2*pos+1);
    int ans2=max_sum(segment_tree, x, y, mid+1, high, 2*pos+2);
    return max(ans1,ans2);}
}
int main(){
    int n;
    cin>>n;
     int arr[n];
     for(int i=0; i<n; i++){
         cin>>arr[i];
     }
     int segment_tree[4*n];
     memset(segment_tree, INT_MIN, sizeof(segment_tree));
    
     build_tree(arr, segment_tree, 0, n-1, 0);
    
     int q;
     cin>>q;
     while(q--){
         int x,y;
         cin>>x>>y;
         x--;
         y--;
         int ans=max_sum(segment_tree, x, y, 0, n-1, 0);
         cout<<ans<<"\n";
     }
}