// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + iinf + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





string s;

vector<pair<int,int>> edges;
vector<bool> selfloop;
vector<vector<int>> adj;
vector<bool> valid;

bool both(int curr) {
    bool a = false;
    bool b = false;
    for(auto next : adj[curr]) {
        if(valid[next]) {
            if(s[next] == 'A') a = true;
            if(s[next] == 'B') b = true;
        }
    }

    return a && b;
}

int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;
    cin >> s;

    selfloop.resize(n, false);
    adj.resize(n);
    valid.resize(n, true);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        edges.pb({n1,n2});
        if(n1 == n2) selfloop[n1] == true;

        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }

    queue<int> removal;
    for(int i = 0; i < n; i++) {
        if(!both(i)) {
            removal.push(i);
        }
    }

    int removed = 0;
    while(!removal.empty()) {
        int curr = removal.front();
        removal.pop();

	if(!valid[curr]) continue;
	valid[curr] = false;
        removed++;

        for(auto next : adj[curr]) {
            if(!valid[next]) continue;

            if(!both(next)) {
                removal.push(next);
            }
        }
    }

    if(removed < n) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
