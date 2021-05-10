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
int link[100010];
int sz[100010];
int mx_size=-1;
int find(int x){
    while(x!=link[x]) x=link[x];
    return x;
}

void unite(int x, int y){
    int a=find(x);
    int b=find(y);

    if(sz[a]<sz[b]) swap(a, b);
    sz[a]+=sz[b];
    mx_size=max(mx_size, sz[a]);
    link[b]=a;
}
void solve(){

    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        link[i]=i;
        sz[i]=1;
    }
    int cnt=n;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        if(find(a)!=find(b)){
            unite(a, b);
            cnt--;
        }

        cout<<cnt<<" "<<mx_size<<"\n";
    }
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
