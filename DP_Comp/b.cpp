#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto& i : v) cin >> i;

    vector<ll> cost(n,inf);
    cost[0] = 0;

    for(ll i = 0; i < n; i++) {
        for(ll j = 1; j <= k; j++) {
            if(i - j >= 0) {
                cost[i] = min(cost[i], cost[i-j] + abs(v[i]-v[i-j]));
            }
        }
    }

    cout << cost[n-1] << endl;
}
