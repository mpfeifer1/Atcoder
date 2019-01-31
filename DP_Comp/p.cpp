#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

vector<vector<ll>> adj;
vector<ll> b;
vector<ll> w;

ll solve(ll curr, ll prev = -1) {
    for(auto next : adj[curr]) {
        if(next == prev) continue;

        solve(next, curr);

        w[curr] *= b[next] + w[next];
        b[curr] *= w[next];

        w[curr] %= mod;
        b[curr] %= mod;
    }

    return (w[curr] + b[curr]) % mod;
}

int main() {
    ll n;
    cin >> n;

    adj.resize(n);
    b.resize(n,1);
    w.resize(n,1);

    for(ll i = 0; i < n-1; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    cout << solve(0) << endl;
}
