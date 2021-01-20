#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long k, a, x, b, y;
    cin >> k >> a >> x >> b >> y;
    auto ans = max(max(k - a, 0ll) * x + max(0ll, k - a - b) * y, max(0ll, k - a - b) * x + max(0ll, k - b) * y);
    cout << ans << '\n';
    return 0;
 
}
