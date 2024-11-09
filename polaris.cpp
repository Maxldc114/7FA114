#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct txt {
    txt () {
        freopen("polaris.in", "r", stdin);
        freopen("polaris.out", "w", stdout);
    }
    ~txt () {
        fclose(stdin);
        fclose(stdout);
    }
} ;
txt tx;
typedef long long ll;
const int N = 1e3 + 9;
const int M = 2e3 + 9;
const int mod = 1e9 + 7;
int n, m;
int dist[N];
vector < int > G[N];
void bfs (int s, int *d) {
    for (int i = 1; i <= n; i++)
        d[i] = M;
    d[s] = 0;
    queue < int > q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u])
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
}
int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, dist);
        sort(dist + 1, dist + n + 1);
        
    }
    return 0;
}