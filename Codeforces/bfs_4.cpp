#include<bits/stdc++.h>
using namespace std;
int id[20005];
bool solve(map<int, vector<int>>&adj, int n){
    vector<int> color(n+1, 0);
    vector<bool> vis(n+1, false);

    queue<int>q;

    for(int i=1; i<=n; i++){
        if(color[i]) continue;
        color[i]=1;
        q.push(i);

        while(!q.empty()){
            int x=q.front();
            q.pop();

            if(vis[x]) continue;
            vis[x]=true;

            for(auto j:adj[x]){
                if(!vis[j]){
                    color[j]=-color[x];
                    q.push(j);
                }
                else{
                    if(color[j]==color[x]) return true;
                }
            }
        }
    } 
    return false;
}
int main(){
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
  //  cout.tie(NULL);

    int t;
    cin>>t;
    int c=1;
    
    while(c<=t){
        int n, m;
        cin>>n>>m;
        
        map<int, vector<int>> adj;
        while(m--){
            int src, des;
            cin>>src>>des;

            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        //cout<<cnt<<" ";
        cout<<"Scenario #"<<c++<<":\n";
        if(solve(adj, n)) cout<<"Suspicious bugs found!\n";
        else cout<<"No suspicious bugs found!\n";
    }
}