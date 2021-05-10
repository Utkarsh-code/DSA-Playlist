#include<bits/stdc++.h>
using namespace std;
#define  int long long 
#define  vi vector<int>
#define  pi pair<int, int>
#define  pii pair<int, pair<int, int>>
#define ff first
#define ss second
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
unordered_map<int, vector<int>> edge;
int node=-1;
vector<int> st;
bool cycle(int src, int vis[], int rec[]){
    vis[src]=1;
    rec[src]=1;
    st.push_back(src);
    for(int x:edge[src]){
        if(!vis[x]){
            if(cycle(x, vis, rec)) return true;
        }
        else if(rec[x]){
            //st.push_back(x);
            node=x;
            return true;
        }
    }
    st.pop_back();
    rec[src]=0;
    return false;
}
void solve(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        edge[a].push_back(b);
    }
    int vis[n+1]={0};
    int rec[n+1]={0};
    int fl=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(cycle(i, vis, rec)){
                fl=1;
                break;
            }
        }
    }
    if(!fl){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    ans.push_back(node);
    //st.pop();
    for(int i=st.size()-1; i>=0; i--){
        ans.push_back(st[i]);
        if(st[i]==node) break;
    }
   // ans.push_back(node);
    cout<<ans.size()<<"\n";
    reverse(ans.begin(), ans.end());
    for(auto i:ans) cout<<i<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++){
        //cout << "Case #" << i  << ": ";
        solve();
    }
    return 0;
}
