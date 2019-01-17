#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;

    vector<ld> coins(n);
    for(auto& i : coins) {
        cin >> i;
    }

    vector<vector<ld>> ans(n+1, vector<ld>(n+1,0));

    ans[0][0] = 1 - coins[0];
    ans[0][1] = coins[0];

    // For each coin
    for(int i = 1; i < n; i++) {
        // For each existing amount of heads
        for(int j = 0; j < n; j++) {
            ans[i][j]   += ans[i-1][j] * (1-coins[i]);
            ans[i][j+1] += ans[i-1][j] * coins[i];
        }
    }

    ld total = 0;
    for(int i = (n+1)/2; i <= n; i++) {
        total += ans[n-1][i];
    }

    cout << fixed;
    cout.precision(10);
    cout << total << endl;
}
