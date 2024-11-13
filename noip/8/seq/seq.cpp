#include <cstdio>
#include <vector>
#include <iostream>
#define int long long
using namespace std;
struct txt {
    txt () {
        freopen("seq.in", "r", stdin);
        freopen("seq.out", "w", stdout);
    }
    ~txt () {
        fclose(stdin);
        fclose(stdout);
    }
} ;
txt tx;
const int inf = 1e9 + 7;
const int K = 1e5 + 9;
int n, k, cnt[K];
vector < int > a[K];
int read () {
    int x = 0;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '?' && c != '-')
        c = getchar();
    bool flag = false;
    if (c == '?') return inf;
    if (c == '-') flag = true;
    else x = c - '0';
    c = getchar();
    while (c <= '9' && c >= '0')
        x = x * 10 + c - '0', c = getchar();
    return flag ? -x : x;
}
bool answer (vector < int > &s, int l, int r) {
    int lnum = s[l - 1], rnum = s[r + 1];
    int len = r - l + 1, lh = len >> 1;
    printf("l:%lld %lld r:%lld %lld\n", l - 1, s[l - 1], r + 1, s[r + 1]);
    printf("size:%llu\n", s.size());
    if (rnum - lnum - 1 < len && l != 1 && r != (int)s.size() - 2)
        return false;
    int sum1 = (2 * lnum + len + 1) * len / 2;
    int sum2 = (2 * rnum - len - 1) * len / 2;
    int sum3 = (lh + 1) * lh;
    if (len & 1 == 0) sum3 -= lh;
    if (sum1 < sum2 && sum1 < sum3) {
        printf("up\n");
        for (int i = l; i <= r; i++)
            s[i] = lnum + i - l + 1;
    } else if (sum2 < sum1 && sum2 < sum3) {
        printf("down\n");
        for (int i = r; i >= l; i--)
            s[i] = rnum + i - r - 1;
    } else {
        printf("mid\n");
        int mid = (l + r) >> 1;
        s[mid] = 0;
        for (int i = mid + 1; i <= r; i++)
            s[i] = i - mid;
        for (int i = mid - 1; i >= l; i--)
            s[i] = i - mid;
    }
    return true;
}
void init () {
    for (int i = 0; i < k; i++)
        a[i].resize(0), cnt[i] = 0;
}
void all_push (int x) {
    for (int i = 0; i < k; i++)
        a[i].push_back(x);
}
void input () {
    n = read(), k = read();
    all_push(-1);
    int lst = inf;
    for (int i = 1; i <= n; i++) {
        int x = read();
        a[i % k].push_back(x);
        if (lst >= x && lst != inf) {
            printf("Incorrect sequence\n");
            printf("first kiled\n");
            return;
        }
    }
    all_push(1);
}
void solve () {
    init();
    input();
    for (int i = 0; i < k; i++) {
        int l = 0, r = 0;
        for (int j = 1; j < (int)a[i].size() - 1; j++) {
            if (a[i][j] == inf && l == 0) l = j;
            if (a[i][j] == inf && l != 0) r = j;
            if (a[i][j] != inf && l != 0 && r != 0)
                if (!answer(a[i], l, r)) {
                    printf("Incorrect sequence\n");
                    printf("second kiled\n");
                    return;
                } else l = r = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%lld%c", a[i % k][++cnt[i % k]], " \n"[i == n]);
}
signed main () {
    int T; scanf("%lld", &T);
    while (T--) solve();
    return 0;
}