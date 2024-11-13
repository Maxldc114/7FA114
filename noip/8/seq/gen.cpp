#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
void negative_rnd () {
    int x = rnd() % 21;
    int type = rnd() % 3;
    if (type == 0) printf("%d ", x);
    else if (type == 1) printf("%d ", -x);
    else printf("? ");
}
int main () {
    freopen("seq.in", "w", stdout);
    int T = rnd() % 10 + 1;
    printf("%d\n", T);
    while (T--) {
        int n = rnd() % 10 + 1, k = rnd() % n + 1;
        printf("%d %d\n", n, k);
        for (int i = 1; i <= n; i++)
            negative_rnd();
        putchar('\n');
    }
    fclose(stdout);
    return 0;
}