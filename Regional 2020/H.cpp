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
 
struct mod_int {
    static const int MOD = 1e9 + 7;
    int value;
 
    mod_int(int value) : value(value) {}
 
    mod_int operator+=(mod_int other) {
        value += other.value;
        if (value >= MOD) value -= MOD;
        return value;
    }
 
    mod_int operator+(mod_int other) {
        mod_int m = *this;
        m += other;
        return m;
    }
 
    mod_int operator*=(mod_int other) {
        value = (1ll * value * other.value) % MOD;
        return *this;
    }
 
    mod_int operator*(mod_int other) {
        return (1ll * value * other.value) % MOD;
    }
};
 
void answer(int x) {
    cout << x << '\n';
    exit(0);
}
 
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    vector<mod_int> fact(n + 1, 1);
    for (int i = 1; i < fact.size(); ++i) fact[i] = fact[i - 1] * i;
    vector<int> count0(8);
    vector<int> count(4);
    for (int i = 0; i < n; ++i) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int z = c[i] - '0';
        int cur;
        if ((x + y + 1) % 10 == z) {
            if (x + y + 1 == z) {
                cur = 0b01 | (x * y * z == 0 ? 0b100 : 0);
            } else {
                cur = 0b11 | (x * y * z == 0 ? 0b100 : 0);
            }
        } else {
            if (x + y == z) {
                cur = 0b00 | (x * y * z == 0 ? 0b100 : 0);
            } else if (x + y == 10 + z) {
                cur = 0b10 | (x * y * z == 0 ? 0b100 : 0);
            } else answer(0);
        }
        count0[cur]++;
        count[cur & 0b011]++;
    }
 
    if (count[0b10] != count[0b01]) answer(0);
    int pairs = count[0b10];
    mod_int ans = fact[pairs];
    int alones = count[0b00];
    int nonzeros = count0[0b000] + count0[0b001];
    ans *= nonzeros;
    ans *= fact[alones + pairs - 1];
    int places = pairs;
    while (count[0b11]--){
        ans *= places++;
    }
    cout << ans.value << '\n';
}