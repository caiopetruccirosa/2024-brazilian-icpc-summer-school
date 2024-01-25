#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

const int MAXN = 100010;

vector<int> grafo[MAXN], vertices_da_componente[MAXN];
vector<pii> resp;
int marc[MAXN], prof[MAXN], pre[MAXN], low[MAXN], comp[MAXN], pilha[MAXN];
int t, c, p;

void dfs(int v) {
    marc[v] = 1;
    for (int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        if (marc[viz] == 0) {
            dfs(viz);
        }
    }
}

void dfs_backedge(int v, int pai) {
    marc[v] = 1;
    for (int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        if (marc[viz] == 0) {
            prof[viz] = prof[v] + 1;
            dfs(viz);
        } else {
            // viz pode ser o pai de v
            if (viz == pai) continue;

            // viz pode ser descendente de v
            // quando olhamos para a back-edge pela segunda vez
            if (prof[viz] > prof[v]) continue;

            // viz é ancestral de v
            // (v, viz) é uma back-edge
            // (viz, v) NÃO É UMA BACK-EDGE
        }
    }
}

void dfs_lowlink(int v, int pai) {
    t++;
    pre[v] = low[v] = t;
    marc[v] = 1;
    for (int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        if (marc[viz] == 0) {
            dfs(viz);
            low[v] = min(low[v], low[viz]);
        } else {
            if (viz == pai) continue;
            low[v] = min(low[v], pre[viz]);
        }
    }
    // verificar se v não é a raiz (v != 1)
    if (v != 1 && low[v] == pre[v])
        resp.push_back({v, pai});
}

void dfs_ebcc(int v, int pai) {
    t++;
    p++;
    pre[v] = low[v] = t;
    marc[v] = 1;
    pilha[p] = v;
    for (int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        if (marc[viz] == 0) {
            dfs(viz);
            low[v] = min(low[v], low[viz]);
        } else {
            if (viz == pai) continue;
            low[v] = min(low[v], pre[viz]);
        }
    }
    if (low[v] == pre[v]) {
        c++;
        int vertice;
        do {
            vertice = pilha[p];
            p--;
            comp[vertice] = c;
            vertices_da_componente[c].push_back(vertice);
        } while (vertice != v);
    }
}