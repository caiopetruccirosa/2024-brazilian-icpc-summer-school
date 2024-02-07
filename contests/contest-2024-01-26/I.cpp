#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

const int MAXN = 300001;

int n, m;
int x[MAXN], dp[MAXN];

int solve(int i) {
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int xi = max(solve(i+1), solve(i+m)+x[i]);
    dp[i] = xi;

    return xi;
}

int main() {_
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> x[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(m) << '\n';

    return 0;
}