#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100010];
vector<int> ans;
void print(){
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
void generate_powerset(int ite){
    print();
    if(ans.size()>=n) return;

    for(int i=ite; i<n; i++){
        ans.push_back(arr[i]);

        generate_powerset(i+1);
        ans.pop_back();
    }
}
int main(){
    cin>>n;

    for(int i=0; i<n; i++) cin>>arr[i];
    generate_powerset(0);
}