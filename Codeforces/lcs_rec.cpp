#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lcs_rec(string s1, string s2, ll n, ll m){
    if(n==0 || m==0) return 0;

    if(s1[n-1]==s2[m-1]) return 1+lcs_rec(s1, s2, n-1, m-1);
    else{
        return max(lcs_rec(s1, s2, n-1, m), lcs_rec(s1, s2, n, m-1));
    }
}
int main(){
    string s1, s2;
    cin>>s1>>s2;

    ll n=s1.length();
    ll m=s2.length();

    cout<<lcs_rec(s1, s2, n, m)<<"\n";
}