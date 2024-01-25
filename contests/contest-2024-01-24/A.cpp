#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

void dfs1(vector<vector<int>> &G, vector<bool> &visited, vector<int> &dist_child, vector<int> &dist, int v) {
    visited[v] = true;
    for (int u: G[v]) {
        if (!visited[u]) {
            dist[u] = dist[v]+1;
            dist_child[u] = dist[u];
            dfs1(G, visited, dist_child, dist, u);
            dist_child[v] = max(dist_child[v], dist_child[u]);
        }
    }
    return;
}

void dfs2(vector<vector<int>> &G, vector<bool> &visited, vector<int> &dist, int v) {
    visited[v] = true;
    for (int u: G[v]) {
        if (!visited[u]) {
            dist[u] = dist[v]+1;
            dfs2(G, visited, dist, u);
        }
    }
    return;
}

int main() {_
    int n, x;
    cin >> n >> x;
    
    vector<vector<int>> G(n+1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist_a(n+1), dist_b(n+1), dist_child(n+1);
    vector<bool> visited(n+1);

    visited.assign(n+1, false);
    dfs1(G, visited, dist_child, dist_a, 1);

    visited.assign(n+1, false);
    dfs2(G, visited, dist_b, x);

    int moves = 0;
    for (int v = 1; v <= n; v++) {
        if (dist_b[v] < dist_a[v]) {
            moves = max(moves, 2*dist_child[v]);
        }
    }
    cout << moves << '\n';

    return 0;
}