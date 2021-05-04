#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
unordered_map<int, vector<int>> edge;

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=0; i<m; i++){
        int src, des;
        cin>>src>>des;

        edge[src].push_back(des);
        edge[des].push_back(src);
    }

    queue<pii> q;
    q.push({0, 0});
    int vis[n]={0};
    int ans=0;
    vis[0]=1;
    while(!q.empty()){
        pii x=q.front();
        q.pop();

        int node=x.ff;
        int lvl=x.ss;
        if(lvl==k) ans++;

        for(int i:edge[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i, lvl+1});
            }
        }
    }
    cout<<ans<<"\n";
}