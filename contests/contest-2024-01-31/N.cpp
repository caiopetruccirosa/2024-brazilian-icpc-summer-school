#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pllll pair<ll,ll>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

ll points_b(vector<pllll> &polygon) {
    ll b = polygon.size();
    for (int i = 0; i < polygon.size(); i++) {
        ll dx = abs(polygon[i].first-polygon[(i+1)%polygon.size()].first);
        ll dy = abs(polygon[i].second-polygon[(i+1)%polygon.size()].second);
        b += abs(gcd(dx, dy)-1);
    }
    return b;
}

ll calculate_area(vector<pllll> &polygon) {
    ll sum = 0;
    for (int i = 0; i < polygon.size(); i++) {
        ll sx = polygon[(i+1)%polygon.size()].first+polygon[i].first;
        ll sy = polygon[(i+1)%polygon.size()].second-polygon[i].second;
        sum += sx*sy;
    }
    return abs(sum)/2;
}

int main() {_
    int n;
    cin >> n;

    vector<pllll> polygon(n);
    for (int i = 0; i < n; i++)
        cin >> polygon[i].first >> polygon[i].second;

    ll A = calculate_area(polygon), B = points_b(polygon);
    cout << A + 1 - B/2 << ' ' << B << '\n';

    return 0;
}