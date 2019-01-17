#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    s = "?" + s;
    t = "?" + t;

    vector<vector<int>> len(s.size(), vector<int>(t.size(),0));
    vector<vector<int>> par(s.size(), vector<int>(t.size(),1));

    // '1' is up
    // '2' is left
    // '3' is upleft

    for(int i = 1; i < s.size(); i++) {
        for(int j = 1; j < t.size(); j++) {

            if(len[i-1][j] > len[i][j]) {
                len[i][j] = len[i-1][j];
                par[i][j] = 1;
            }

            if(len[i][j-1] > len[i][j]) {
                len[i][j] = len[i][j-1];
                par[i][j] = 2;
            }

            if(len[i-1][j-1] + 1 > len[i][j] && s[i] == t[j]) {
                len[i][j] = len[i-1][j-1] + 1;
                par[i][j] = 3;
            }
        }
    }

    int x = s.size()-1;
    int y = t.size()-1;

    string ret = "";
    while(x > 0 && y > 0) {
        if(par[x][y] == 1) {
            x--;
        }
        else if(par[x][y] == 2) {
            y--;
        }
        else if(par[x][y] == 3) {
            ret.push_back(s[x]);
            x--;
            y--;
        }
    }

    reverse(ret.begin(),ret.end());
    cout << ret << endl;
}
