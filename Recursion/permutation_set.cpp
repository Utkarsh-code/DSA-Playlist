#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100010];
int freq[100010]={0};
vector<int> ans;

void print(){
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

void generate_allpermutation(){
     if(ans.size()==n){
         print();
         return;
     }
     
    for(int i=0; i<n; i++){
     //  if(freq[i] || (i>0 && arr[i]==arr[i-1] && !freq[i-1])) continue;   // for distinct permutation.
        if(freq[i]==0){
            freq[i]=1;
        ans.push_back(arr[i]);

        generate_allpermutation();
        ans.pop_back();
        freq[i]=0;
        }
    }
    return;
}

int main(){
   // int n;
    cin>>n;

    for(int i=0; i<n; i++) cin>>arr[i];
    generate_allpermutation();
}