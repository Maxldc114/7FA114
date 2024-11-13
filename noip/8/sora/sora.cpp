#include <cstdio>
#include <vector>
using namespace std;
struct txt {
    txt () {
        freopen("sora.in", "r", stdin);
        freopen("sora.out", "w", stdout);
    }
    ~txt () {
        fclose(stdin);
        fclose(stdout);
    }
} ;
txt tx;
typedef long long ll;
const int N = 3e5 + 9;
const int M = 35;
int n, m, a[N];
ll f[N][M], po2[M];
vector < int > G[N];
void init () {
    po2[0] = 1;
    for (int i = 1; i <= 30; i++)
        po2[i] = po2[i - 1] << 1ll;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void dfs_init (int u, int fa) {
    for (int i = 0; i <= 30; i++)
        f[u][i] = (a[u] >> i) & 1;
    for (int v : G[u])
        if (v != fa) {
            dfs_init(v, u);
            for (int i = 0; i < 30; i++)
                f[u][i] += f[v][i + 1];
        }
}
void dfs_ans (int u, int fa) {
    for (int v : G[u])
        if (v != fa) {
            for (int i = 0; i < 30; i++)
                f[v][i] += f[u][i + 1] - f[v][i + 2];
            dfs_ans(v, u);
        }
}
int main () {
    init();
    dfs_init(1, 0);
    dfs_ans(1, 0);
    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        for (int j = 0; j <= 30; j++)
            ans += f[i][j] * po2[j];
        printf("%lld ", ans);
    }
    return 0;
}