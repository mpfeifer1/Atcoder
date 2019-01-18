#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 62;

// Actual array
vector<ll> v;

// 2D memo
vector<vector<ll>> memo;

// Solves [lo,hi] with the current player
ll solve(ll lo, ll hi, bool b) {
    // Chech memo
    if(memo[lo][hi] != inf) return memo[lo][hi];

    // Base case
    if(lo == hi) {
        if(b) {
            memo[lo][hi] = v[lo];
            return v[lo];
        }
        else {
            memo[lo][hi] = -v[lo];
            return -v[lo];
        }
    }

    // General case
    ll ans;
    if(b) {
        ans = max(solve(lo+1,hi,!b) + v[lo], solve(lo,hi-1,!b) + v[hi]);
    }
    else {
        ans = min(solve(lo+1,hi,!b) - v[lo], solve(lo,hi-1,!b) - v[hi]);
    }
    memo[lo][hi] = ans;
    return ans;
}

int main() {
    ll n;
    cin >> n;
    v.resize(n);
    for(auto& i : v) {
        cin >> i;
    }
    memo.resize(n+1,vector<ll>(n+1,inf));
    cout << solve(0,n-1,true) << endl;
}
