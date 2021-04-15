#include<bits/stdc++.h>
using namespace std;
int id[100005];
int n, m;
int parent(int x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void merge(int x, int y){
    int a=parent(x);
    int b=parent(y);
    id[a]=id[b];
}
int solve(pair<int, pair<int,int>> adj[]){
    int mincost=0;
    for(int i=0; i<m; i++){
        int w=adj[i].first;
        int x=adj[i].second.first;
        int y=adj[i].second.second;

        if(parent(x)!=parent(y)){
            mincost+=w;
            merge(x, y);
        }
    }
    return mincost;
}
int main(){
    //int n,m;
    cin>>n>>m;

    pair<int, pair<int, int>> adj[m];

    for(int i=0; i<m; i++){
        int src, dis, w;
        cin>>src>>dis>>w;
        //adj[i].make_pair({w, make_pair({src, dis})});
        adj[i]=(make_pair(w, make_pair(src, dis)));
    }
    for(int ut=1; ut<=100005; ut++) {id[ut]=ut;}
    sort(adj, adj+m);
    int ans=solve(adj);
    cout<<ans<<"\n";
}