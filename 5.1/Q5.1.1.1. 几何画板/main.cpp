#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <iostream>
typedef double lf;
using namespace std;
const lf PI = 3.14159265358979323846;
typedef complex<lf> comp;
struct Edge {
    comp u, v;
} ;
const int N = 5e4 + 9;
int T, cnt;
lf dot (comp x, comp y) {
    return x.real() * x.imag() + y.real() * y.imag();
}
lf cross (comp x, comp y) {
    return x.real() * y.imag() - x.imag() * y.real();
}
lf Abs (comp x) {
    return sqrt(x.imag() * x.imag() + x.real() * x.real());
}
struct Angle {
    comp x, y;
    lf cos () {
        return dot(x, y) / (Abs(x) * Abs(y));
    }
    lf sin () {
        return cross(x, y) / (Abs(x) * Abs(y));
    }
} ;
Angle ang[N];
comp c[N];
Edge e[N];
string s;
lf S(comp x, comp y, comp z) {
    comp a = y - x, b = z - x;
    return cross(a, b);
}
lf dist(comp x, comp y) {
    comp a = x - y;
    return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("4.in", "r", stdin);
    freopen("ans.txt", "w", stdout);
    // printf("sin45:%.10lf\n", sin(45.0 * PI / 180.0));
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        cin >> s;
        if (s == "point") {
            lf x, y;
            scanf("%lf%lf", &x, &y);
            c[i] = { x, y };
        }
        if (s == "move") {
            int a, b;
            scanf("%d%d", &a, &b);
            c[i] = c[a] + c[b];
            printf("%.10llf %.10llf\n", c[i].real(), c[i].imag());
        }
        if (s == "area") {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            printf("%.10lf\n", S(c[x], c[y], c[z]) / 2.0);
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
            comp a = (e[y].v - e[y].u) * (comp){ 0.0, 1.0 } + c[x];
            e[i] = { c[x], a };
        }
        if (s == "angle") {
            int x, y;
            scanf("%d%d", &x, &y);
            ang[i] = {c[x], c[y]};
            // printf("point1:%.10lf %.10lf\n", c[x].real(), c[x].imag());
            // printf("point2:%.10lf %.10lf\n", c[y].real(), c[y].imag());
        }
        if (s == "rotate") {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            printf("point1:%.10lf %.10lf\n", c[x].real(), c[x].imag());
            printf("point2:%.10lf %.10lf\n", c[y].real(), c[y].imag());
            printf("angle:%.10lf %.10lf\n", ang[z].cos(), ang[z].sin());
            comp an = (comp){ang[z].cos(), ang[z].sin()};
            comp a = c[x] - c[y];
            a *= an;
            c[i] = a + c[y];
            printf("%.10lf %.10lf\n", c[i].real(), c[i].imag());
        }
    }
    return 0;
}