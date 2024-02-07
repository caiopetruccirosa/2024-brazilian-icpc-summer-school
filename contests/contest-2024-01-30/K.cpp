#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

int main() {_
    int n;
    cin >> n;

    vector<vector<int>> G(n);
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        p[i] = a;
        G[i].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        
    }

    return 0;
}