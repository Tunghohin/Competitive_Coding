#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

int num_cnt[10];

void solve()
{
	string num;
	cin >> num;

	int len = num.length();
	for (auto c : num)
	{
		num_cnt[c - '0']++;
	}

	int type_cnt = 0;
	for (int i = 0; i <= 9; i++) if (num_cnt[i]) type_cnt++;

	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}