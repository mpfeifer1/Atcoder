#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for(auto& i : v) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    vector<vector<int>> best(n, vector<int>(3,0));
    best[0] = v[0];
    for(int i = 1; i < n; i++) {
        best[i][0] = max({v[i][0] + best[i-1][1], v[i][0] + best[i-1][2]});
        best[i][1] = max({v[i][1] + best[i-1][0], v[i][1] + best[i-1][2]});
        best[i][2] = max({v[i][2] + best[i-1][0], v[i][2] + best[i-1][1]});
    }

    cout << max({best[n-1][0], best[n-1][1], best[n-1][2]}) << endl;
}
