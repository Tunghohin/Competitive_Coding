#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int a_cnt = 0, t_cnt = 0;
	for (auto c : s) {
		if (c == 'T') t_cnt++;
		else a_cnt++;

		if (t_cnt >= (n + 1) / 2) {
			cout << "T" << '\n';
			return 0;
		}
		if (a_cnt >= (n + 1) / 2) {
			cout << "A" << '\n';
			return 0;
		}
	}
}
