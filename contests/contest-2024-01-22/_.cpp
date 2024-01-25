#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define LIM 1000000007
#define INF (1ll << 60)

using namespace std;

void solve(vector<vector<int>> &G, int n) {
    stack<int> s;
    
    s.push(1);
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