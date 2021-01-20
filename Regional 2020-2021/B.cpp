#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve();
 
signed main() {
    int t = 1;
    cin >> t;
    for (int q = 0; q < t; ++q) solve();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
 
int sum(int n1, int n2, int m1, int m2, int m) {
    if (n1 > n2 || m1 > m2) return 0;
    int fst = n1 * m + m1 + 1;
    int scd = fst + (m2 - m1);
    int sum1 = (fst + scd) * (scd - fst + 1) / 2;
    int sum2 = sum1 + m * (m2 - m1 + 1) * (n2 - n1);
    int res = (sum1 + sum2) * (n2 - n1 + 1) / 2;
    return res;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    int hans, nn;
    {
        int l = -1, r = n;
        auto diff = [n, m](int N) { return sum(0, N, 0, m - 1, m) - sum(N + 1, n - 1, 0, m - 1, m); };
        while (r - l > 1) {
            int N = (l + r) / 2;
            (diff(N) <= 0 ? l : r) = N;
        }
        if ((l + 1 <= n)) ++l;
        while (abs(diff(l - 1)) <= abs(diff(l)) && (l - 1 >= 0)) --l;
        hans = abs(diff(l));
        nn = l;
    }
    int vans, mm;
    {
        int l = -1, r = m;
        auto diff = [n, m](int M) { return sum(0, n - 1, 0, M, m) - sum(0, n - 1, M + 1, m - 1, m); };
        while (r - l > 1) {
            int M = (l + r) / 2;
            (diff(M) <= 0 ? l : r) = M;
        }
        if ((l + 1 <= m)) ++l;
        while (abs(diff(l - 1)) <= abs(diff(l)) && (l - 1) >= 0) --l;
        vans = abs(diff(l));
        mm = l;
    }
    if (n == 1 || (m > 1 && hans >= vans)) {
        cout << "V " << mm + 2 << '\n';
    } else {
        cout << "H " << nn + 2 << '\n';
    }
}
