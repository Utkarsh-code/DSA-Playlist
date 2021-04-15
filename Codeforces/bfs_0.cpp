#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
    int f, st, en , up, dn;
    cin>>f>>st>>en>>up>>dn;

    vector<int> dis(f+1, INF);
    vector<bool> vis(f+1, false);

    queue<int> q;
    q.push(st);
    dis[st]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(vis[x]) continue;
         vis[x]=true;

         int a=x+up;
         int b=x-dn;

         if((a>0 and a<=f) and vis[a]==false) {
             dis[a]=min(dis[a], dis[x]+1);
             q.push(a);
         }

         if((b>0 && b<=f) and vis[b]==false){
             dis[b]=min(dis[b], dis[x]+1);
             q.push(b);
         }
    }
    //for(int i=1; i<=f; i++){
    //    cout<<dis[i]<<" ";
    //}
    if(dis[en]==INF)  cout<<"use the stairs\n";
    else cout<<dis[en]<<"\n";
}