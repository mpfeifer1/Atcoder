#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

ll n;
vector<ll> v;

vector<vector<ll>> memo;
vector<vector<ll>> size;

// Find the cheapest cost to combine the range [lo,hi]
ll solve(ll lo, ll hi) {
    if(memo[lo][hi] != inf) return memo[lo][hi];

    if(lo == hi) {
        memo[lo][hi] = 0;
        return 0;
    }

    ll best = inf;
    for(ll i = lo; i < hi; i++) {
        ll here = solve(lo,i) + solve(i+1,hi);
        best = min(best,here);
    }
    best += size[lo][hi];

    memo[lo][hi] = best;
    return best;
}

void sizes(ll lo, ll hi) {
    if(size[lo][hi] != inf) return;

    if(lo == hi) {
        size[lo][hi] = v[lo];
        return;
    }

    ll best = inf;
    for(int i = lo; i < hi; i++) {
        sizes(lo,i);
        sizes(i+1,hi);
        ll here = size[lo][i] + size[i+1][hi];
        best = min(best, here);
    }

    size[lo][hi] = best;
}

int main() {
    ll n;
    cin >> n;

    v.resize(n);
    for(auto& i : v) {
        cin >> i;
    }

    memo.resize(n+1,vector<ll>(n+1,inf));
    size.resize(n+1,vector<ll>(n+1,inf));

    sizes(0,n-1);
    cout << solve(0,n-1) << endl;
}
