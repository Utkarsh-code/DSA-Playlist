#include<bits/stdc++.h>
using namespace std;
int n, t;
vector<pair<int,int>> ans;
bool dfs(int v, vector<bool> vis, vector<bool> list, map<int, vector<int>>&adj){
    if(!vis[v]){
        vis[v]=true;
        list[v]=true;
    }

    for(auto i:adj[v]){
        if(!vis[i] && dfs(i, vis, list, adj)){
           // ans.push_back(v);
           // ans.push_back(i);
           return true;
        }
        else if(list[i]){
            //ans.push_back(v);
            //ans.push_back(i);
            return true;
        }
    }
    list[v]=false;
    return false;
}
bool cycle(map<int, vector<int>>&adj){
    vector<bool> vis(n+1, false);
    vector<bool> rec(n+1, false);

    for(int i=1; i<=n; i++){
        if(!vis[i]){ if(dfs(i, vis, rec, adj)) return true;}
    }
    return false;
}
int main(){
    cin>>n>>t;

    map<int, vector<int>> per;
    map<int, vector<int>> temp;
    for(int i=0; i<t; i++){
        int src,dis;
        cin>>src>>dis;

        temp[src].push_back(dis);
        if(cycle(temp)){
            ans.push_back({src, dis});
            temp.erase(src);

            for(auto v: per[src]){
                if(v!=dis) temp[src].push_back(dis);
            }
            
        }
        else {per[src].push_back(dis);} //cout<<src<<" "<<dis<<"\n";}
    }
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";

        //if(i%2!=0) cout<<"\n";
    }
    cout<<"0 0\n";
}