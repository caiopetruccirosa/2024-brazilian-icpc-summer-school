#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

void dfs(vector<vector<int>> &G, vector<int> &distance, vector<bool> &visited, vector<bool> &connect, vector<bool> &connected_children, int v, int p) {
    visited[v] = true;
    distance[v] = distance[p]+1;

    int connectable_children = 0;
    for (int u: G[v]) {
        if (!visited[u]) {
            dfs(G, distance, visited, connect, connected_children, u, v);
            if (connect[u] && !connected_children[u]) {
                connectable_children++;
            }
        }
    }

    if (distance[v] > 2 || connectable_children > 1) {
        connect[v] = true;
        distance[v] = 1;
        for (int u: G[v]) {
            if (u != p && connect[u] && !connected_children[u]) {
                connected_children[v] = true;
                connect[u] = false;
                distance[u] = 2;
            }
        }
    }
    return;
}

int main() {_
    int n;
    cin >> n;

    vector<vector<int>> G(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> distance(n+1, INF);
    vector<bool> visited(n+1, false), connect(n+1, false), connected_children(n+1, false);
    distance[0] = -1;

    dfs(G, distance, visited, connect, connected_children, 1, 0);

    // cout << "Distâncias:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << "\t1 -> " << i << ": " << distance[i] << '\n';
    // }

    // cout << "Visitado:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << "\t" << i << ": " << visited[i] << '\n';
    // }

    // cout << "Conectado:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << "\t" << i << ": " << connect[i] << '\n';
    // }

    // cout << "Conectou filhos:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << "\t" << i << ": " << connected_children[i] << '\n';
    // }

    int count = 0;
    for (int i = 1; i <= n; i++)
        if (connect[i])
            count++;

    cout << count << '\n';

    return 0;
}