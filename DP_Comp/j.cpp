#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

vector<vector<vector<ld>>> memo;
int n;

ld solve(vector<int>& v) {
    if(v[0] == n) return 0;
    if(memo[v[1]][v[2]][v[3]] != -1) return memo[v[1]][v[2]][v[3]];

    // Expected value to pick one at this step
    ld ans = (ld)n / (n-v[0]);

    for(int i = 1; i <= 3; i++) {
        if(v[i] == 0) continue;
        vector<int> next = v;
        next[i]--;
        next[i-1]++;
        // Expected value later if we pick up one w/ this val
        ans += ((ld)v[i] / (n-v[0])) * solve(next);
    }

    memo[v[1]][v[2]][v[3]] = ans;
    return ans;
}

int main() {
    cin >> n;
    vector<int> v(4,0);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v[t]++;
    }

    memo.resize(n+1, vector<vector<ld>>(n+1, vector<ld>(n+1,-1)));

    cout << fixed;
    cout.precision(10);
    cout << solve(v) << endl;
}
