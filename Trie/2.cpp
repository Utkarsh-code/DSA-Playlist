#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define ff first
#define ss second
#define pb push_back
#define pi pair<int, int>
int mod=1e9+7;
int inf=1e18;
int ninf=-1e18;
 
int pown(int x, int y){
    int res=1;
 
    while(y){
        if(y&1) res=(x*res)%mod;
         x=(x*x)%mod;
       y>>=1;
    }
    return res;
}

struct node{
  //  int terminal;
    node* next[26];
    int mark;
    node(){
        mark=0;
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
    }
};

void solve(){
     int n;
     cin>>n;
   //  node *root=new node();
    /* string ans;
     int ok=0;
     int id=0, node;

     vector<vector<int>> trie(100010, vector<int>(26, 0));
     vector<int> terminal(100010);

     for(int i=0; i<n; i++){
         string s;
         cin>>s;
        node=0;
          int cnt=0;
        for(char ch:s){
           if(trie[node][ch-'a']==0){
               trie[node][ch-'a']=++id;
               cnt++;
           }
           node=trie[node][ch-'a'];

           if(terminal[node] && ok==0){
               ok=1;
               ans=s;
           }
        }
        if(cnt==0 && ok==0){
           ok=1;
           ans=s;
        }
        terminal[node]=1;
     }
     if(ok==0){
         cout<<"GOOD SET\n";
     }
     else{
         cout<<"BAD SET\n";
         cout<<ans<<"\n";
     }*/
    int ok=0;
    string ans;
    node *root=new node();

     while(n--){
         string s;
         cin>>s;
    
         node *curr=root;
        // curr->terminal++;
         int cnt=0;
         for(char ch:s){

             if(curr->next[ch-'a']==NULL){
                 curr->next[ch-'a']=new node();
                 cnt++;
             }
             curr=curr->next[ch-'a'];

             if(curr->mark>0 && ok==0){
                 ok=1;
                 ans=s;
                 break;
             }

         }

         if(cnt==0 && ok==0){
            ok=1;
            ans=s;
            break;
         }

         curr->mark=1;
     }


     if(ok==0){
         cout<<"GOOD SET\n";
     }
     else{
         cout<<"BAD SET\n";
         cout<<ans<<"\n";
     }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        cout<<setprecision(10)<<fixed;
        solve();
    }
    return 0;
}