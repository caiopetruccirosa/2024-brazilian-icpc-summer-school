#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

pii directions[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

ll dfs(
    vector<string> &grid, 
    vector<vector<bool>> &visited, 
    vector<vector<pii>> &parent,
    pii pos, 
    pii par,
    int n, 
    int m
) {
    if (pos.first < 0 || pos.first >= n)
        return 0;
    if (pos.second < 0 || pos.second >= m)
        return 0;

    visited[pos.first][pos.second] = true;
    parent[pos.first][pos.second] = par;
    
    ll acc = 0;
    for (int i = 0; i < 4; i++) {
        pii d = directions[i];
        if (pos.first+d.first >= 0 &&
            pos.first+d.first < n &&
            pos.second+d.second >= 0 &&
            pos.second+d.second < m) {
            if (!visited[pos.first+d.first][pos.second+d.second] && grid[pos.first+d.first][pos.second+d.second] == '.') {
                acc += dfs(grid, visited, parent, {pos.first+d.first, pos.second+d.second}, par, n, m);
            } else if (grid[pos.first+d.first][pos.second+d.second] == '*') {
                acc++;
            }
        }
    }
    return acc;
}

int main() {_
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<ll>> dp(n, vector<ll>(m));
    vector<vector<pii>> parent(n, vector<pii>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        pii pos = {x-1, y-1};
        ll ans = -1;
        if (!visited[pos.first][pos.second]) {
            ans = dfs(grid, visited, parent, pos, pos, n, m);
            dp[pos.first][pos.second] = ans;
        } else {
            pii p = parent[pos.first][pos.second];
            ans = dp[p.first][p.second];
        }
        cout << ans << '\n';
    }

    return 0;
}