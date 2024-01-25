#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define LIM 1000000007
#define INF (1ll << 60)

using namespace std;

int bfs(vector<vector<int>> &G, int n, int s) {
    vector<bool> visited(n+1, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: G[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return i;
        }
    }
    return -1;
}

void solve(vector<vector<int>> &G, int n) {
    for (int i = 1; i <= n; i++) {
        int v = bfs(G, n, i);
        if (v > 0) {
            cout << "NO\n";
            cout << i << ' ' << v << '\n';
            return;
        }
    }
    cout << "YES\n";
    return;
}

int dfs(vector<vector<int>> &G, vector<bool> &visited, vector<int> &reached, int v, int acc) {
    if (reached[v] != -1) {
        return reached[v];
    }
    visited[v] = true;
    for (int u: G[v]) {
        if (!visited[u]) {
            acc = dfs(G, visited, reached, u, acc+1);
        }
    }
    return acc;
}


int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    solve(G, n);

    return 0;
}