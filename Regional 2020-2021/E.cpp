#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
 
void solve(){
    long long d, m, w, i, j, k;
    cin >> d >> m >> w >> i >> j >> k;
    --i, --j, --k;
    long long day = i + j * d + k * d * m;
    cout << char('a' + day % w) << '\n';
}
