#include<bits/stdc++.h>
using namespace std;
string ans="";
void dfs(int v, map<int, vector<int>>& adj, vector<int>&vis){
    vis[v]=2;

    for(auto i:adj[v]){
        if(vis[i]!=2) dfs(i, adj, vis);
    }
    ans+=v+'a';
}
int main(){
    int n;
    cin>>n;
     
    map<int, vector<int>> adj;
    vector<int> vis(26,0);
    while(n--){
        string s;
        cin>>s;
        
        for(int i=0; i<s.length()-1; i++){
            adj[s[i]-'a'].push_back(s[i+1]-'a');
            vis[s[i+1]-'a']=3;
        }
        if(vis[s[0]-'a']!=3) vis[s[0]-'a']=1;
    }
    for(int i=0; i<26; i++){
        if(vis[i]==1) dfs(i, adj, vis);
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
}