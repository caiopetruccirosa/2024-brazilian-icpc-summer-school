#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define LIM 1000000007
#define INF (1ll << 60)

using namespace std;

int dfs(vector<vector<int>> &G, vector<bool> &visited, vector<bool> &has_cat, int v, int m, int cats, int restaurants) {
    if (has_cat[v] && cats+1 > m) {
        return restaurants;
    }

    int vis = 0;
    visited[v] = true;
    for (int u: G[v]) {
        if (!visited[u]) {
            vis++;
            if (has_cat[v]) {
                restaurants = dfs(G, visited, has_cat, u, m, cats+1, restaurants);
            } else {
                restaurants = dfs(G, visited, has_cat, u, m, 0, restaurants);
            }
        }
    }

    if (vis == 0) {
        restaurants++;
    }

    return restaurants;
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n+1);
    vector<bool> visited(n+1, false);
    vector<bool> has_cat(n+1, false);
    for (int i = 1; i <= n; i++) {
        bool a;
        cin >> a;
        has_cat[i] = a;
    }
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << dfs(G, visited, has_cat, 1, m, 0, 0) << '\n';

    return 0;
}