#include <bits/stdc++.h>
 
using namespace std;
//#define int long long
 
void solve();
 
signed main() {
    int t = 1;
//    cin >> t;
    for (int q = 0; q < t; ++q) solve();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
 
struct edge {
    int b, e;
    int i;
 
    edge(int b, int e, int i) : b(b), e(e), i(i) {}
 
    edge() {}
};
 
bool solve(vector<edge> edges, int len);
 
void solve() {
    int n;
    cin >> n;
    vector<edge> edges(n);
    int len = -1;
    for (int i = 0; i < n; ++i) {
        int m, s;
        cin >> m >> s;
        vector<int> p(m);
        for (int &x : p) cin >> x;
        edges[i] = {p[0], s - p.back(), i + 1};
        for (int j = 1; j < p.size(); ++j) {
            if (len != -1 && p[j] - p[j - 1] != len) {
                cout << "No\n";
                return;
            }
            len = p[j] - p[j - 1];
        }
    }
    if (n == 1) {
        cout << "Yes\n1\n";
        return;
    }
    if (len == -1) {
        vector<int> b, e;
        for (auto &edge : edges) b.push_back(edge.b);
        for (auto &edge : edges) e.push_back(edge.e);
        sort(b.begin(), b.end());
        sort(e.rbegin(), e.rend());
        if (!solve(edges, b[0] + e[0]) &&
            !solve(edges, b[1] + e[0]) &&
            !solve(edges, b[0] + e[1]) &&
            !solve(edges, b[1] + e[1])) {
            cout << "No\n";
            return;
        }
    } else if (!solve(edges, len)) {
        cout << "No\n";
        return;
    }
}
 
bool solve(vector<edge> edges, int len) {
    for (auto &e : edges) e.e = len - e.e;
    map<int, vector<edge>> graph;
    for (auto &e : edges) graph[e.b].push_back(e);
    map<int, int> in;
    for (auto &e : edges) in[e.e]++;
    for (auto &e : edges) in[e.b]--;
    auto s = find_if(in.begin(), in.end(), [](pair<int, int> entry) { return entry.second == -1; });
    int start = s == in.end() ? graph.begin()->first : s->first;
    vector<int> ans;
    function<void(int)> dfs = [&](int cur) {
        while (!graph[cur].empty()) {
            auto e = graph[cur].back();
            graph[cur].pop_back();
            dfs(e.e);
            ans.push_back(e.i);
        }
    };
    dfs(start);
    reverse(ans.begin(), ans.end());
    if (ans.size() < edges.size()) return false;
    vector<int> p(ans.size());
    for (int i = 0; i < ans.size(); ++i) p[ans[i] - 1] = i;
    sort(edges.begin(), edges.end(), [&](edge a, edge b) { return p[a.i - 1] < p[b.i - 1]; });
    for (int j = 1; j < edges.size(); ++j) if (edges[j - 1].e != edges[j].b) return false;
    cout << "Yes\n";
    for (int x : ans) cout << x << ' ';
    return true;
}
