#include<bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<int, vector<int>> adj;
int ans[100010]={0};
void print(){
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}
bool issafe(int node, int idx){

    int fl=0;
    for(int i=1; i<idx; i++){
        if(ans[i]==node) return false;
    }

    if(idx>0){
        for(auto i:adj[ans[idx-1]]){
            if(i==node) {fl=1; break;}
        }
    }
    if(fl==0) return false;

    return true;
}
bool solve_hamiltoniancycle(int idx){
    if(idx==n+1){
        int fl=0;
        for(auto i:adj[idx-1]){
            if(i==ans[1]){ fl=1; break;}
        }
        
        if(fl){
         //   ans[idx]=ans[1];
            print(); return false;
        }
        return false;
    }
    for(int i=2; i<=n; i++){
        if(issafe(i, idx)){
            ans[idx]=i;

            if(solve_hamiltoniancycle(idx+1)) return true;
          //  ans.pop_back();
         // ans[idx]=-1;
        }
        ans[idx]=-1;
    }
    return false;
}
int main(){
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int src,des;
        cin>>src>>des;

        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    for(int i=0; i<=n; i++) ans[i]=-1;
    ans[1]=1;
    ans[0]=-1;
    bool ans=solve_hamiltoniancycle(2);
}