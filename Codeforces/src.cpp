#include<bits/stdc++.h>
#define iii pair<int, pair<int, int> >
using namespace std;

bool visited[55][1005];
int dist[55][1005];
int tolls[55][55];
int times[55][55];
int n, p;

void dijkstra() {
    priority_queue<iii, vector<iii >, greater<iii > > pq;
    pq.push(make_pair(0, make_pair(1, 0)));
    dist[1][0]=0;
    while (!pq.empty()) {
        iii top=pq.top();
        pq.pop();
        int nd=(top.second).first;
        int ndtime=(top.second).second;
        visited[nd][ndtime]=1;
        for (int i=1; i<=n; i++) {
            int toll=tolls[nd][i];
            int time=times[nd][i];
            if (time+ndtime<=p && nd!=i) {
                if (!visited[i][time+ndtime]) {
                    if (dist[i][time+ndtime]>dist[nd][ndtime]+toll) {
                        dist[i][time+ndtime]=dist[nd][ndtime]+toll;
                        pq.push(make_pair(dist[i][time+ndtime], make_pair(i, time+ndtime)));
                    }
                }
            }
        }
    }
}

main() {
    while (1) {
        scanf("%d %d", &n, &p);
        if (n==0 && p==0) break;
        for (int i=0; i<55; i++) {
            for (int j=0; j<1005; j++) {
                dist[i][j]=1<<30;
                visited[i][j]=0;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) scanf("%d", &times[i][j]);
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) scanf("%d", &tolls[i][j]);
        }
        dijkstra();
        int ans=1<<30, index;
        for (int i=1; i<=p; i++) {
            if (ans>dist[n][i]) {
                ans=dist[n][i];
                index=i;
            }
        }

        printf("%d %d\n", ans, index);
    }
}
