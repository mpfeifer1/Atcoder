#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> memo(k+1,false);
    vector<int> vals(n);
    for(auto& i : vals) {
        cin >> i;
    }
    sort(vals.begin(),vals.end());
    for(int j = 0; j <= k; j++) {
        for(auto i : vals) {
            if(j-i < 0) continue;
            memo[j] = memo[j] || !memo[j-i];
        }
    }
    if(memo[k]) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}
