#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
template<typename T>istream& operator >> (istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<typename T>ostream& operator << (ostream& os, vector<T>& v) { for (const auto& x : v) os << x << "\n"; return os; }
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
 
bool good(int mask1, int mask2) {
    if ((mask1 & 4) == 0) return true;
    if ((mask1 & 2) == 0 && (mask2 & 4) == 0) return true;
    if ((mask1 & 2) == 0 && (mask2 & 2) == 0) return true;
    if ((mask1 & 2) == 0 && (mask2 & 1) == 0) return true;
    if ((mask1 & 1) == 0 && (mask2 & 2) == 0) return true;
    if ((mask1 & 1) == 0 && (mask2 & 1) == 0) return true;
    if ((mask2 & 1) == 0) return true;
    return false;
}
 
int answer(int n, vector<int> &a) {
    int ans = 0;
    for (int mask = 0; mask < 8; ++mask) {
        vector<vector<int>> dp(n, vector<int>(8, -1e15));
        int sum = 0;
        if (mask & 1) sum += a[0];
        if (mask & 2) sum += a[1];
        if (mask & 4) sum += a[2];
        if (mask != 7) dp[3][(mask >> 1) + 4] = sum + a[3];
        dp[3][(mask >> 1)] = sum;
        for (int j = 4; j < a.size(); ++j) {
            for (int m = 0; m < 8; ++m) {
                if (m != 7) dp[j][(m >> 1) + 4] = max(dp[j - 1][m] + a[j], dp[j][(m >> 1) + 4]);
                dp[j][(m >> 1)] = max(dp[j - 1][m], dp[j][(m >> 1)]);
            }
        }
        for (int m = 0; m < 8; ++m) if (good(m, mask)) ans = max(ans, dp.back()[m]);
    }
    return ans;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int q;
    cin >> q;
    vector<int> ans(q + 1);
    for (int i = 0; i <= q; ++i) {
        ans[i] = answer(n, a);
        if (i == q) answer(ans);
        int p, v;
        cin >> p >> v;
        a[p - 1] = v;
    }
}
