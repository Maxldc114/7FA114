#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <iostream>
using namespace std;
typedef complex<double> comp;
struct Edge {
    comp u, v;
} ;
const int N = 5e4 + 9;
int T, cnt;
double ang[N];
comp c[N];
Edge e[N];
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
    freopen("4.in", "r", stdin);
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
        if (s == "angle") {
            int x, y;
            scanf("%d%d", &x, &y);
            ang[i] = abs(arg(c[y]) - arg(c[x]));
            printf("point1:%lf %lf\n", c[x].real(), c[x].imag());
            printf("point2:%lf %lf\n", c[y].real(), c[y].imag());
        }
        if (s == "rotate") {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            printf("point1:%lf %lf\n", c[x].real(), c[x].imag());
            printf("point2:%lf %lf\n", c[y].real(), c[y].imag());
            printf("angle:%lf\n", ang[z]);
            comp an = {cos(ang[i]), sin(ang[i])};
            comp a = c[x] - c[y];
            a *= an;
            c[i] = a + c[y];
            printf("%.10lf %.10lf\n", c[i].real(), c[i].imag());
        }
    }
    return 0;
}