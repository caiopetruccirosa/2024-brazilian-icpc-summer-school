#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

int main() {_
    int n, k;
    cin >> n >> k;

    vector<set<ll>> knapsack(k+1);
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    knapsack[0].insert(0);
    for (int i = 1; i <= k; i++) {
        for (int d: knapsack[i-1]) {
            for (int j = 1; j <= n; j++) {
                knapsack[i].insert(d+a[j]);
            }
        }
    }

    vector<ll> ans(knapsack[k].begin(), knapsack[k].end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size()-1)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}