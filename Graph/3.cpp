#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> edge;
int ans=0;
void dfs(int src, int des){

    if(src==des) {ans++;
    return;
    }
    for(int x:edge[src]){
            dfs(x, des);
    }
}
int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
        //edge[b].push_back(a);
    }
    int src, des;
    cin>>src>>des;
    dfs(src, des);

    cout<<ans<<"\n";
}