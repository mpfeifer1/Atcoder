#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;

    vector<vector<char>> v(h, vector<char>(w));
    vector<vector<ll>> ways(h, vector<ll>(w,0));
    for(ll i = 0; i < h; i++) {
        for(ll j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }

    ways[0][0] = 1;
    for(ll i = 0; i < h; i++) {
        for(ll j = 0; j < w; j++) {
            if(v[i][j] == '#') continue;
            if(i > 0) {
                ways[i][j] += ways[i-1][j];
                ways[i][j] %= mod;
            }
            if(j > 0) {
                ways[i][j] += ways[i][j-1];
                ways[i][j] %= mod;
            }
        }
    }

    cout << ways[h-1][w-1] << endl;
}
