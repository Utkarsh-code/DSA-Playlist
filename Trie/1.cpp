#include<bits/stdc++.h>
using namespace std;
string ans="";
void dfs(int node, string sam, vector<vector<int>>&nxt, vector<bool> &terminal){
    if(sam.length()>ans.length()){
        ans=sam;
    }

    for(int i=0; i<26; i++){
        int tmp=nxt[node][i];
        if(tmp!=0 && terminal[tmp]){
            sam+=char(i+'a');
            dfs(tmp, sam, nxt, terminal);
            sam.pop_back();
        }
    }
}
int main(){
    int n;
    cin>>n;
    
    vector<string> arr;
    for(int i=0; i<n; i++){
        string st;
        cin>>st;
        arr.push_back(st);
    }
    
    vector<vector<int>> nxt(1, vector<int>(26));
    vector<bool> terminal(1);
    int id=0;
    for(string s:arr){
        int node=0;
        for(char c:s){
            if(nxt[node][c-'a']==0){
                nxt.push_back(vector<int>(26));
                terminal.push_back(false);
                nxt[node][c-'a']=++id;
            }
            node=nxt[node][c-'a'];
            //terminal[node]=true;
        }
        terminal[node]=true;
    }
    string sam="";
    dfs(0, sam, nxt, terminal);
    cout<<ans<<"\n";
}