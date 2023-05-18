#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> res;
    int n;
    cin >> n;

    int last = 0;    
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        if (last != 0) {
            if (last < tmp) {
                for (int j = last + 1; j < tmp; j++) res.push_back(j);     
            }
            else {
                for (int j = last - 1; j > tmp; j--) res.push_back(j);
            }
        }
        res.push_back(tmp);
        last = tmp;
    }

    for (auto u : res) cout << u << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
}
