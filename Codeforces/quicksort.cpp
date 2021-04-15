#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll parti(ll a[], ll lb, ll ub){
    ll pivot=a[ub];
    ll i=lb-1;

    for(int j=lb; j<ub; j++){
        if(a[j]<=pivot){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[++i], a[ub]);
    return i;
}

void quick_sort(ll a[], ll lb, ll ub){
    if(lb<ub){
        ll q=parti(a, lb, ub);

        quick_sort(a,lb, q-1);
        quick_sort(a, q+1, ub);
    }
}

int main(){
    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    quick_sort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}