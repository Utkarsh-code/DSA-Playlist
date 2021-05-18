#include<bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<int, vector<int>> adj;
int st, en;
int ans=0;
vector<int> arr;
void print(){
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}
void solve_totalpath(int src){
    arr.push_back(src);
    if(src==en){
        print();
        ans++;
        return;
    }
    for(auto i:adj[src]){
        solve_totalpath(i);
        arr.pop_back();
    }
}
int main(){
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int src, des;
        cin>>src>>des;
        adj[src].push_back(des);
    }
    cin>>st>>en;
    solve_totalpath(st);
    cout<<ans<<"\n";
}