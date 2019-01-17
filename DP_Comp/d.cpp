#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, w;
    cin >> n >> w;

    vector<ll> best(w+1,0);

    for(int i = 0; i < n; i++) {
        ll weight, value;
        cin >> weight >> value;

        for(int j = w-weight+1; j >= 0; j--) {
            best[j+weight] = max(best[j+weight], best[j] + value);
        }
    }

    ll ans = 0;
    for(auto& i : best) {
        ans = max(i,ans);
    }

    cout << ans << endl;
}
