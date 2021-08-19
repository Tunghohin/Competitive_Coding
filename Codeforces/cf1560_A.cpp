#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> v;
	for (int i = 1; i <= 100000; i++)
	{
		int x = i;
		if (!(x % 3) || x % 10 ==3) continue;
		else v.push_back(i);
	}

	int T;
	cin >> T;

	while (T--)
	{
		int x;
		cin >> x;
		cout << v[x  - 1] << '\n';
	}

}