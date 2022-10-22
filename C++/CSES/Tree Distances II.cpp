
#include <bits/stdc++.h>
#define int long long
#define V vector<int>
#define VV vector<V>
#define VP vector<pii>
#define VVP vector<VP>
#define pii pair<int, int>
#define F first
#define S second
#define rep(x, y ,z) for(int x = y; x < z; x++)
#define rep2(x, y ,z) for(int x = y; x <= z; x++)
#define rrep(x, y ,z) for(int x = y; x >= z; x--)
#define ln "\n"
#define sp " "
#define INF (int) 1e18
 
using namespace std;
 
int n;
VV graph;
V ans;
V sum;
 
void dfs(int parent, int now, int depth) {
 
    ans[1] += depth;
    for (auto i : graph[now]) {
        if (i == parent) {
            continue;
        }
 
        dfs(now, i, depth + 1);
 
        sum[now] += sum[i];
    }
 
    sum[now]++;
 
}
 
void dfs2(int parent, int now) {
 
    for (auto i : graph[now]) {
        if (i == parent) {
            continue;
        }
 
        ans[i] = ans[now] + (n - sum[i]) - (sum[i]);
 
        dfs2(now, i);
    }
 
}
 
void solve() {
 
    cin >> n;
 
    graph.resize(n + 1);
    ans.resize(n + 1);
    sum.resize(n + 1);
 
    rep2 (i, 1, n - 1) {
        int a, b;
        cin >> a >>b;
 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    dfs(-1, 1, 0);
    dfs2(-1, 1);
 
    rep2 (i, 1, n) {
        cout << (ans[i]) << sp;
    }
 
}
 
signed main() {
 
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	solve();
 
	return 0;
 
}
