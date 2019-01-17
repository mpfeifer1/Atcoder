#include <bits/stdc++.h>

using namespace std;
int inf = 1 << 29;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) cin >> i;

    vector<int> cost(n,inf);
    cost[0] = 0;
    for(int i = 0; i < n; i++) {
        if(i - 1 >= 0) {
            cost[i] = min(cost[i], cost[i-1] + abs(v[i]-v[i-1]));
        }
        if(i - 2 >= 0) {
            cost[i] = min(cost[i], cost[i-2] + abs(v[i]-v[i-2]));
        }
    }

    cout << cost[n-1] << endl;
}
