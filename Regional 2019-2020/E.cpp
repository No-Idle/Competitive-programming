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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int ans = 0;
    int sum = 0;
    int delta = 1e10;
    for (int i = 0; i < n; ++i) sum += a[i];
    int now = 0;
    for (int i = 0; i < n; ++i) {
        if (delta > abs(sum - now - now)) {
            delta = sum - now - now;
            ans = i;
        }
        now += a[i];
    }
    answer(ans);
}
