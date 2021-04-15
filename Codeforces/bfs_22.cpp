#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;

    while(t--){
        ll a, b, c;
        cin>>a>>b>>c;

        if(c>a && c>b) {cout<<"NO\n"; continue;}
        queue<pair<ll, ll>> q;
        q.push(make_pair(0, 0));

        set<pair<ll, ll>> s;
        ll ans=0;
        ll fl=0;
        while(!q.empty()){
            ll sz=q.size();

            for(ll i=0; i<sz; i++){
                   auto x=q.front();
                   q.pop();

                   ll curr_fi=x.first;
                   ll curr_se=x.second;

                   if(curr_fi==c || curr_se==c){fl=1; break;}
                   auto p=make_pair(curr_fi, curr_se);
                   if(s.find(p)!=s.end()) continue;
                   s.insert((make_pair(curr_fi, curr_se)));

                   //1 case 
                   ll zero=0;
                   q.push(make_pair(curr_fi, b));
                   q.push(make_pair(a, curr_se));
                   q.push(make_pair(0, curr_se));
                   q.push(make_pair(curr_fi, 0));
                   ll new1=max(zero, curr_fi+curr_se-b);
                   ll new2=curr_se+curr_fi-new1;
                   q.push(make_pair(new1, new2));
                   new2=max(zero, curr_fi+curr_se-a);
                   new1=curr_fi+curr_se-new2;
                   q.push(make_pair(new1, new2));
            }
            if(fl){
                cout<<"YES"<<"\n";
                break;
            }
            ans++;
        }
        if(fl==0) cout<<"NO\n";
    }
}