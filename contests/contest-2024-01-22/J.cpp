#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define LIM 1000000007
#define INF (1ll << 60)

using namespace std;

bool dfs(vector<vector<int>> &G, vector<bool> &visited, vector<int> &prev, int v) {
    visited[v] = true;
    for (int u: G[v]) {
        if (visited[u] && u != prev[v]) {
            prev[u] = v;
            visited[u] = true;
            return u;
        } else if (!visited[u]) {
            prev[u] = v;
            int w = dfs(G, visited, prev, u);
            if (w > 0) {
                return w;
            }
        }
    }
    return -1;
}

void solve(vector<vector<int>> &G, int n) {
    vector<int> path, prev(n+1, -1);
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int v = dfs(G, visited, prev, i);
            if (v > 0) {
                vector<int> path;
                int current = v;
                do {
                    path.push_back(current);
                    current = prev[current];
                } while (current != v);
                path.push_back(current);
                
                cout << path.size() << '\n';
                for (int u: path) {
                    cout << u << ' ';
                }
                cout << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    solve(G, n);

    return 0;
}