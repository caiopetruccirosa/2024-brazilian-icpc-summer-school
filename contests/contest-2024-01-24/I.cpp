#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

vector<vector<int>> adj, adj_rev, adj_scc, root_children;
vector<bool> used;
vector<int> order, component, leaves, roots, root_nodes, component_is_leaf;
set<int> cities;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

void dfs3(int r) {
    used[r] = true;

    if (adj_scc[r].empty())
        component_is_leaf[r] = 1;

    for (auto v : adj_scc[r])
        if (!used[v])
            dfs3(v);
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n+1, vector<int>());
    adj_rev.assign(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n+1, false);
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n+1, false);
    roots.assign(n+1, 0);
    component_is_leaf.assign(n+1, 0);
    adj_scc.assign(n+1, vector<int>());
    root_children.assign(n+1, vector<int>());
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (!used[v]) {
            dfs2(v);

            int root = component.front();
            for (auto u : component) {
                roots[u] = root;
                root_children[root].push_back(u);;
            }
            root_nodes.push_back(root);
            component.clear();
        }
    }

    for (int v = 1; v <= n; v++) {
        for (auto u : adj[v]) {
            int root_v = roots[v], root_u = roots[u];
            if (root_u != root_v) {
                adj_scc[root_v].push_back(root_u);
            }
        }
    }

    used.assign(n+1, false);
    for (int i = 1; i <= n; i++)
        if (!used[roots[i]])
            dfs3(roots[i]);

    used.assign(n+1, false);
    ull ans = 0;
    for (int r: root_nodes) {
        if (component_is_leaf[r]) {
            for (int c: root_children[r]) {
                cities.insert(c);
                ans++;
            }
        }
    }

    cout << ans << '\n';
    for (int c: cities) {
        cout << c << ' ';
    }
    cout << '\n';
}