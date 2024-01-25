#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

const int MAXN = 1000;
const int RAIZ = 1;

vector<int> grafo[MAXN];
vector<int> idAresta[MAXN];

int marc[MAXN];
int marcAresta[MAXN];
int pontoDeArticulacao[MAXN];
int pre[MAXN];
int low[MAXN];
int componenteDaAresta[MAXN];
int arestasPorComponentes[MAXN];
int pilhaArestas[MAXN];

int t, c, p;

void novaComponenteBiconexa(int idA) {
    c++;
    int a;
    do {
        a = pilhaArestas[p];
        p--;
        componenteDaAresta[a] = c;
        if (p == -1) break;
    } while (a != idA);
}

void dfs(int v, int pai) {
    t++;
    pre[v] = t;
    low[v] = t;
    marc[v] = 1;
    int qtdFilhos = 0;
    for (int i = 0; i < grafo[v].size(); i++) {
        int viz = grafo[v][i];
        int idA = idAresta[v][i];

        if (marcAresta[idA] == 1) continue;

        marcAresta[idA] = 1;
        p++;
        pilhaArestas[p] = idA;

        if (marc[viz] == 0) {
            qtdFilhos++;
            dfs(viz, v);
            low[v] = min(low[v], low[viz]);

            bool achouNovaComponente = false;
            if (v == RAIZ && qtdFilhos >= 2) achouNovaComponente = true;
            if (v != RAIZ && low[viz] >= pre[v]) achouNovaComponente = true;

            if (achouNovaComponente) {
                pontoDeArticulacao[v] = 1;
                novaComponenteBiconexa(idA);
            }
        } else {
            low[v] = min(low[v], pre[viz]);
        }
    }
}

int main() {_
    int num_test;
    cin >> num_test;

    for (int test = 1; test <= num_test; test++) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            grafo[i] = vector<int>();
            idAresta[i] = vector<int>();
        }

        memset(marc, 0, sizeof(marc));
        memset(marcAresta, 0, sizeof(marcAresta));
        memset(pontoDeArticulacao, 0, sizeof(pontoDeArticulacao));
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(componenteDaAresta, 0, sizeof(componenteDaAresta));
        memset(arestasPorComponentes, 0, sizeof(arestasPorComponentes));
        memset(pilhaArestas, 0, sizeof(pilhaArestas));

        int a = 1;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            if (u != v) {
                grafo[u].push_back(v);
                grafo[v].push_back(u);
                idAresta[u].push_back(a);
                idAresta[v].push_back(a);
                a++;
            }
        }

        t = 0, p = -1, c = 0;
        dfs(RAIZ, 0);
        novaComponenteBiconexa(-1);

        for (int i = 1; i <= a; i++) {
            arestasPorComponentes[componenteDaAresta[i]]++;
        }

        ull ans = 1;
        for (int i = 1; i <= c; i++) {
            ans = ans * arestasPorComponentes[i];
        }
        cout << "Case " << test << ": " << ans << '\n';
    }

    return 0;
}