#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
string s;
ll x, y;
vector<ll> edges[300005];
ll indegree[300005];
vector<ll> toposort;
ll dp[300005];
 
void solve(int tc = 0) {
	cin >> n >> m >> s;
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		++indegree[y];
	}
	
	queue<ll> q;
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		++cnt;
		ll x = q.front();
		q.pop();
		toposort.push_back(x);
		
		for (ll y: edges[x]) {
			--indegree[y];
			if (indegree[y] == 0) {
				q.push(y);
			}
		}
	}
	
	if (cnt < n) {
		cout << -1 << '\n';
		return;
	}
	
	ll ans = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		memset(dp, 0, sizeof(dp));
		
		for (ll x: toposort) {
			if (s[x] == c) ++dp[x];
			for (ll y: edges[x]) {
				dp[y] = max(dp[y], dp[x]);
			}
			ans = max(ans, dp[x]);
		}
	}
	cout << ans << '\n';
}
 
// two pointers? maybe
// xor tricks (or general bitwise)
// tutorial on my template
 
int main() {
	//#ifdef galen_colin_local
	//	auto begin = std::chrono::high_resolution_clock::now();
	//#endif
	
	//send help
 
	//#ifndef galen_colin_local
		// usaco("dining");
	//#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	//cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	//#ifdef galen_colin_local
	//	auto end = std::chrono::high_resolution_clock::now();
	//	cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	//#endif
} 