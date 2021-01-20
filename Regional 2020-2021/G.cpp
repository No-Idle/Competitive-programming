#include <bits/stdc++.h>
 
using namespace std;
 
void solve();
 
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
 
int c;
 
void go(vector<vector<int>> &ans, int x, int y) {
    if (x + 1 == ans.size() && y == ans[0].size()) {
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j < y; ++j) {
                cout << (ans[i][j] < 3 ? ans[i][j] : 3) << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    if (y == ans[0].size()) {
        go(ans, x + 1, 0);
        return;
    }
 
    int cur = 0b111;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (ans[i][j] == ans[i][y] && ans[i][j] == ans[x][j]) {
                cur &= ~ans[i][j];
            }
        }
    }
    if (c == 3 && (cur & 4)) {
        ans[x][y] = 4;
        go(ans, x, y + 1);
    }
    if (cur & 2) {
        ans[x][y] = 2;
        go(ans, x, y + 1);
    }
    if (cur & 1) {
        ans[x][y] = 1;
        go(ans, x, y + 1);
    }
    ans[x][y] = 0;
}
 
void check_patterns(int n, int m) {
    vector<string> ansAA{"3312122312",
                         "2113221233",
                         "3212233131",
                         "2122113323",
                         "3223311212",
                         "1333213122",
                         "1123232311",
                         "3231121123",
                         "2231312331",
                         "1311332223"};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ansAA[j][i] << ' ';
        }
        cout << '\n';
    }
    exit(0);
}
 
void solve() {
    int n, m;
    cin >> n >> m >> c;
    if (c == 3) check_patterns(n, m);
    vector<vector<int>> ans(n, vector<int>(m));
    go(ans, 0, 0);
}
