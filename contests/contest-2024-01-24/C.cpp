#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

int paths;

void dfs(vector<vector<int>> &G, vector<bool> &visited, int v, int t) {
    visited[v] = true;
    for (int u: G[v]) {
        if (u == t) {
            paths++;
            return;
        }
        if (!visited[u]) {
            dfs(G, visited, u, t);
        }
    }
    return;
}


int main() {_
    int r, c, q;
    cin >> r >> c >> q;

    while (!(r == 0 && c == 0 && q == 0)) {
        vector<vector<int>> G(r+1);
        for (int i = 0; i < c; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        while (q--) {
            int s, t;
            cin >> s >> t;

            vector<bool> visited(r+1, false);
            paths = 0;
            dfs(G, visited, s, t);
            if (paths == 1) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
        cout << "-\n";
        cin >> r >> c >> q;
    }

    return 0;
}