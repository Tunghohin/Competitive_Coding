#include <iostream>

using namespace std;

long long a[100010];

int low_bit(int x)
{
	return x & -x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];


}