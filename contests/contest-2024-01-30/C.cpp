#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

int jump_spaces(string &s, int i) {
    while (s[i] == ' ')
        i++;
    return i;
}

int build_tree(string &s, vector<vector<int>> &T) {
    stack<int> st;
    int i = jump_spaces(s, 0);
    int root = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        root *= 10;
        root += s[i] - '0';
        i++;
    }
    st.push(root);
    while (i < s.size()) {
        i = jump_spaces(s, i);
        if (s[i] == '(') {
            i++;
            i = jump_spaces(s, i);
            int v = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                v *= 10;
                v += s[i] - '0';
                i++;
            }
            st.push(v);
            i = jump_spaces(s, i);
        }
        if (s[i] == ')') {
            i++;
            int v = st.top(); st.pop();
            int p = st.top();
            T[p].push_back(v);
        }
    }
    return root;
}

bool dfs(vector<vector<int>> &T1, vector<vector<int>> &T2, int v) {
    sort(T1[v].begin(),T1[v].end());
    sort(T2[v].begin(),T2[v].end());

    if (T1[v] != T2[v])
        return false;

    for (int u: T1[v])
        if (!dfs(T1, T2, u))
            return false;

    return true;
}

int main() {_
    string s1, s2;
    vector<vector<int>> T1(1000005, vector<int>()), T2(1000005, vector<int>());

    getline(cin,s1);
    getline(cin,s2);

    int root1 = build_tree(s1, T1);
    int root2 = build_tree(s2, T2);

    if (root1 == root2 && dfs(T1, T2, root1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}