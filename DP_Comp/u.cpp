#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

ll n;
vector<vector<ll>> v;
vector<ll> cost;
vector<ll> dp;

ll getval(ll mask) {
    vector<ll> on;
    for(ll i = 0; i < n; i++) {
        if(mask & (1<<i)) {
            on.push_back(i);
        }
    }

    ll total = 0;
    for(ll i = 0; i < on.size(); i++) {
        for(ll j = i+1; j < on.size(); j++) {
            total += v[on[i]][on[j]];
        }
    }

    return total;
}

ll solve(ll mask) {
    if(dp[mask] != -inf) return dp[mask];
    if(mask == 0) return 0;
    ll val = cost[mask];

    for(ll sub = mask; sub; sub = (sub-1)&mask) {
        if(sub == mask) continue;
        val = max(val, solve(sub) + solve(mask^sub));
    }

    return dp[mask] = val;
}

int main() {
    cin >> n;

    dp.resize(1<<n,-inf);
    v.resize(n,vector<ll>(n));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    cost.resize(1<<n,-inf);
    for(ll i = 0; i < 1<<n; i++) {
        cost[i] = getval(i);
    }

    cout << solve((1<<n)-1) << endl;
}
