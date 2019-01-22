#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

int main() {
    ll n, w;
    cin >> n >> w;

    vector<ll> best(100001,inf);
    best[0] = 0;

    for(int i = 0; i < n; i++) {
        ll wi, vi;
        cin >> wi >> vi;

        for(ll i = 100001; i >= 0; i--) {
            if(i + vi > 100000) {
                continue;
            }
            best[i+vi] = min(best[i+vi],best[i]+wi);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < best.size(); i++) {
        if(best[i] <= w) {
            ans = i;
        }
    }
    cout << ans << endl;
}
