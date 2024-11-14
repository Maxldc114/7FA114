#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <iostream>
using namespace std;
const int N = 5e4 + 9;
typedef complex<double> comp;
int T, cnt;
comp c[N];
struct Edge {
    comp u, v;
} e[N];
string s;
double S(comp x, comp y, comp z) {
    comp a = y - x, b = z - x;
    return a.real() * b.imag() - a.imag() * b.real();
}
double dist(comp x, comp y) {
    comp a = x - y;
    return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("3.in", "r", stdin);
    freopen("ans.txt", "w", stdout);
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        cin >> s;
        if (s == "point") {
            double x, y;
            scanf("%lf%lf", &x, &y);
            c[i] = { x, y };
        }
        if (s == "move") {
            int a, b;
            scanf("%d%d", &a, &b);
            c[i] = c[a] + c[b];
            printf("%.10lf %.10lf\n", c[i].real(), c[i].imag());
        }
        if (s == "area") {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            printf("%.10lf\n", S(c[x], c[y], c[z]) / 2);
        }
        if (s == "line") {
            int u, v;
            scanf("%d%d", &u, &v);
            e[i] = { c[u], c[v] };
        }
        if (s == "dist") {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%.10lf\n", abs(S(c[x], e[y].u, e[y].v)) / dist(e[y].u, e[y].v));
        }
        if (s == "perp") {
            int x, y;
            scanf("%d%d", &x, &y);
            comp a = (e[y].v - e[y].u) * (comp){ 0, 1 } + c[x];
            e[i] = { c[x], a };
        }
    }
    return 0;
}