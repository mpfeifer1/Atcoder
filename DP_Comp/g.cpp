#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n,0);
    vector<int> path(n,0);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].push_back(n2);
        deg[n2]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) q.push(i);
    }

    int best = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        best = max(best, path[curr]);

        for(auto next : adj[curr]) {
            path[next] = max(path[next],path[curr]+1);
            deg[next]--;
            if(deg[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << best << endl;
}
