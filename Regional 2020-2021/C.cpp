#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve();
 
signed main() {
    int t = 1;
//    cin >> t;
    for (int q = 0; q < t; ++q) solve();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
#define count first
#define chr second
void solve() {
    string dna;
    cin >> dna;
    vector<pair<int, char>> s{{0, 0}};
    for (int i = 0; i < dna.size(); ++i) {
        if (!isdigit(dna[i])) s.emplace_back(1, dna[i]);
        else {
            int code = 0;
            for (; isdigit(dna[i]); ++i) code = code * 10 + dna[i] - '0';
            s.emplace_back(code, dna[i]);
        }
    }
    s.emplace_back(0, 0);
    vector<int> prefix(s.size());
    for (int i = 1; i < s.size(); ++i) prefix[i] = s[i].count + prefix[i - 1];
    auto len = [](int x) { return (x == 1 ? 0 : (int) to_string(x).size()); };
    int mindelta = 0, maxdelta = 0;
    for (int i = 1; i + 1 < s.size(); ++i) {
        if (s[i].count == 1) mindelta = min(mindelta, -1ll);
        if (s[i].count == 1 && s[i + 1].chr == s[i - 1].chr) {
            mindelta = min(mindelta, -2ll - len(s[i - 1].count) - len(s[i + 1].count) +
                                     len(s[i - 1].count + s[i + 1].count));
        }
        if (len(s[i].count) > len(s[i].count - 1)) mindelta = min(mindelta, -1ll);
    }
 
    for (int i = 1; i + 1 < s.size(); ++i) {
        if (mindelta == 0) {
            cout << "2 1\n";
            break;
        }
        if ((s[i].count == 1 || len(s[i].count) > len(s[i].count - 1)) && mindelta == -1ll) {
            cout << "2 " << prefix[i - 1] + 1 << '\n';
            break;
        }
        if (s[i].count == 1 && s[i + 1].chr == s[i - 1].chr &&
            mindelta == -2ll - len(s[i - 1].count) - len(s[i + 1].count) +
                        len(s[i - 1].count + s[i + 1].count)) {
            cout << "2 " << prefix[i - 1] + 1 << '\n';
            break;
        }
    }
    auto slice_p = [len](int x) -> pair<int, int> {
        auto s = to_string(x);
        if (s.size() > 1 && s[0] == '1' && s[1] != '0') {
            for (int i = 1; i < s.size(); ++i) s[i] = '0';
            return {atoi(s.c_str()), s.size() + s.size() - 1};
        }
        return {x / 2, len(x / 2) + len((x + 1) / 2)};
    };
    auto slice = [slice_p](int x) -> int { return slice_p(x).chr; };
    for (int i = 1; i + 1 < s.size(); ++i) {
        if (s[i].count == 1 || s[i].count == 2) maxdelta = max(maxdelta, 1ll);
        if (s[i].count == 3) maxdelta = max(maxdelta, 2ll);
        if (len(s[i].count + 1) > len(s[i].count)) maxdelta = max(maxdelta, 1ll);
        if (s[i].count > 3) {
            maxdelta = max(maxdelta, slice(s[i].count) - len(s[i].count) + 2);
        }
    }
    for (int i = 1; i + 1 < s.size(); ++i) {
        char other;
        if (s[i].chr == 'A' || s[i].chr == 'T') {
            other = 'A' + 'T' - s[i].chr;
        } else {
            other = 'C' + 'G' - s[i].chr;
        }
        if ((s[i].count < 3 && maxdelta == 1ll) || (s[i].count == 3 && maxdelta == 2ll)) {
            cout << "1 " << prefix[i - 1] + 1 << ' ' << other << '\n';
            break;
        }
        if (len(s[i].count + 1) > len(s[i].count) && maxdelta == 1ll) {
            cout << "1 " << prefix[i - 1] << ' ' << s[i].chr << '\n';
            break;
        }
        if (s[i].count > 3 && maxdelta == slice(s[i].count) - len(s[i].count) + 2) {
            cout << "1 " << slice_p(s[i].count).count + prefix[i - 1] << ' ' << other << '\n';
            break;
        }
    }
 
}
