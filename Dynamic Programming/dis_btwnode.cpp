#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> edge;
#define  LO 18
int depth[200010];
int up[200010][LO];
void dfs(int node){

    for(auto x:edge[node]){
       // if(x==par) continue;

        depth[x]=1+depth[node];
        up[x][0]=node;

        for(int j=1; j<LO; j++){
            up[x][j]=up[up[x][j-1]][j-1];
        }
        dfs(x);
    }
}
int get_lca(int a, int b){
    if(depth[a]<depth[b]) swap(a, b);
     
     int depth_diff=depth[a]-depth[b];

     for(int i=LO-1; i>=0; i--){
         if((depth_diff)&(1<<i)) a=up[a][i];
     }

     if(a==b) return a;

     for(int i=LO-1; i>=0; i--){
         if(up[a][i]!=up[b][i]){
             a=up[a][i];
             b=up[b][i];
         }
     }
    return up[a][0];
}
int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        
        int m;
        cin>>m;
        
        for(int j=0; j<m; j++){
            int num;
            cin>>num;
            edge[i].push_back(num);
        }
    }
    dfs(0);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int lca=get_lca(a, b);
       // int ans=depth[a]+depth[b]-2*depth[lca];

        cout<<lca<<"\n";
    }
}