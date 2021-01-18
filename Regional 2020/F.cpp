#include <bits/stdc++.h>
 
using namespace std;
 
void solve();
 
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
 
using ll = long long;
 
ll to_int(const string &s) {
    ll res = 0;
    for (char c : s) (res *= 10) += c - '0';
    return res;
}
 
void solve() {
    vector<ll> beautiful, semi_beautiful;
    for (int len = 1; len <= 18; ++len) {
        for (int digit = 0; digit < 10; ++digit) {
            auto b = string(len, '0' + digit);
            if (digit) {
                beautiful.push_back(to_int(b));
                semi_beautiful.push_back(to_int(b));
            }
            for (int pos = 0; pos < len; ++pos) {
                for (int odd = pos == 0; odd < 10; ++odd) {
                    auto c = b;
                    c[pos] = odd + '0';
                    semi_beautiful.push_back(to_int(c));
                }
            }
        }
    }
    sort(semi_beautiful.begin(), semi_beautiful.end());
    semi_beautiful.resize(unique(semi_beautiful.begin(), semi_beautiful.end()) - semi_beautiful.begin());
 
 
    do {
        long long x, k;
        cin >> x >> k;
        auto &mood = (k ? semi_beautiful : beautiful);
        cout << *lower_bound(mood.begin(), mood.end(), x) << endl;
    } while (false);
}