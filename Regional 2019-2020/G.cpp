#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
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
 
unordered_map<int, pair<int, int> > dp;
 
pair<int, int> answer(vector<int>& a, int b, int hint) {
    if (b == 0) return { 0, 0 };
    int i;
    if ((hint == a.size() || a[hint] > b) && (hint == 0 || a[hint - 1] <= b))
        i = hint - 1;
    else
        i = (upper_bound(a.begin(), min(a.begin()+hint+1, a.end()), b) - a.begin()) - 1LL;
 
    pair<int, int> an1 = dp[b % a[i]] == pair<int, int>(0, 0) ? dp[b % a[i]] = answer(a, b % a[i], i - 1) : dp[b % a[i]];
    pair<int, int> an2 = dp[a[i] - 1] == pair<int, int>(0, 0) ? dp[a[i] - 1] = answer(a, a[i] - 1, i - 1) : dp[a[i] - 1];
 
    if (an1.first + (b / a[i]) > an2.first + (b / a[i]) - 1) {
        return dp[b] = { an1.first + (b / a[i]), an1.second + b / a[i] * a[i] };
    }
    else {
        return dp[b] = { an2.first + (b / a[i]) - 1, an2.second + (b / a[i] - 1) * a[i] };
    }
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int q;
    cin >> q;
    vector<pair<int, int>> ans(q);
    for (int i = 0; i < q; ++i) {
        int b;
        cin >> b;
        ans[i] = dp[b] == pair<int, int>(0, 0) ? dp[b] = answer(a, b, n) : dp[b];
    }
    for (int i = 0; i < q; ++i) cout << ans[i].second << " " << ans[i].first << "\n";
}
