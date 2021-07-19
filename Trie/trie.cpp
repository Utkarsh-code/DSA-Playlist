#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<string> str;
    for(int i=0; i<n; i++){
        string st;
        cin>>st;

        str.push_back(st);
    }

    vector<vector<int>> trie(100010, vector<int>(26, 0));
    vector<int> terminal(100010, 0);

    int id=0;
    //bulid trie;

    for(string s:str){
        int node=0;
        for(char ch:s){
            if(trie[node][ch-'a']==0)
            {
                trie[node][ch-'a']=++id;
            }
            node=trie[node][ch-'a'];
        }
        terminal[node]=1;
    }

    // search word;

    int q;
    cin>>q;

    while(q--){
        string s;
        cin>>s;

        int node=0;
        int ok=0;
        for(char ch:s){
            if(trie[node][ch-'a']==0)
            {
                ok=1;
                break;
            }
            node=trie[node][ch-'a'];
        }
        if(ok){
            cout<<0<<"\n";
            continue;
        }

        if(terminal[node])
        {
            cout<<1<<"\n";
        }
        else
        {
            cout<<0<<"\n";
        }
    }
}