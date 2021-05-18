#include<bits/stdc++.h>
using namespace std;
int n, m;
int noOfcolor;
int color[100010]={0};
unordered_map<int, vector<int>> mp;
void print(){
    for(int i=1; i<=n; i++) cout<<color[i]<<" ";
    cout<<"\n";
}
bool issafe(int node, int colour){

    for(auto i:mp[node]){
        if(color[i]==colour) return false;
    }
    return true;
}
bool solve_mcoloring(int node){
     if(node==n+1){
         print();
         return true;
     }
      
    for(int i=1; i<=noOfcolor; i++){
          if(issafe(node, i)){
           color[node]=i;

           if(solve_mcoloring(node+1)) return true;
           color[node]=0;}
    }
    return false;
}
int main(){
    cin>>n>>m>>noOfcolor;

    for(int i=0; i<m; i++){
        int src, des;
        cin>>src>>des;

        mp[src].push_back(des);
        mp[des].push_back(src);
    }
    if(solve_mcoloring(1)){
        cout<<"M coloring is possible for the given graph.\n";
    }
    else{
        cout<<"Not possible to color the vertex of a given graph.\n";
    }
}