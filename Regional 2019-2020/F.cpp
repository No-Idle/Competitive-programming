#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
template<typename T>istream& operator >> (istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<typename T>ostream& operator << (ostream& os, vector<T>& v) { for (const auto& x : v) os << x << " "; return os; }
struct exit_exception {};
template<typename T>void answer(T ans, ostream& os = cout) { os << ans; throw exit_exception(); }
void solve();
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    do { try { solve(); } catch (exit_exception) {} } while (--t);
    return 0;
}
 
void solve() {
    int n, del;
    cin >> n >> del;
    vector<vector<int> > G(n, vector<int>(n));
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            int a = i, b = j;
            if (b == 0) {
                G[a][b] = a; continue;
            }
            G[a][b] = G[b][a % b];
        }
    }
    int ans = 0;
    for (int x = 1; x < n; ++x) {
        for (int y = 1; x * y < n; ++y) {
            int LK = n - (x * y);
            int c = 1;
            for (; c <= x; ++c) if ((c * y) % x == LK % x) break;
            if (LK - c * y <= 0) continue;
            if ((LK - c * y) % x != 0) continue;
            int d = (LK - c * y) / x;
            ans += (d - 1) / (y / G[x][y]) + 1;
        }
    }
    if (del == 0) answer(ans);
    for (int b = 1; b < n; ++b) {
        for (int c = 1; c < b; ++c) {
            if ((del * b - n) % c == 0 && del * b - n > 0 && (del * b - n) / c < del) ans--;
        }
    }
    for (int b = 1; b < n; ++b) {
        if (b == del) continue;
        for (int c = 1; c < b; ++c) {
            if ((del * b - n) % c == 0 && del * b - n > 0 && (del * b - n) / c < del) ans--;
        }
    }
    cout << ans;
}
