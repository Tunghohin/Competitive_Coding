#include <iostream>
#include <vector>

using namespace std;

bool comp(vector<int> &A,vector<int> &B)
{
	if (A.size()!=B.size()) return A.size()>B.size();
	else
	{
		for (int i=A.size()-1;i>=0;i--)
		{
			if (A[i]!=B[i]) return A[i]>B[i];
		}
	}
	return true;
}

vector<int> sub(vector<int> &A,vector<int> &B)
{
	vector<int> C;
	for (int i=0,t=0;i<A.size();i++)
	{
		t=A[i]-t;
		if (i<B.size()) t-=B[i];
		C.push_back((t+10)%10);
		if (t<0) t=1;
		else t=0;
	}
	while (C.size()>1&&C.back()==0) C.pop_back();
	return C;
}

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	vector<int> A;
	vector<int> B;

	for (int i = s.length() - 1; i >= 0; i--) B.push_back(s[i] - '0');

	if (s[0] == '9')
	{
		for (int i = 0; i <= s.length(); i++) A.push_back(1);
	}
	else if (s[0] == '8')
	{
		for (int i = 0; i <= s.length(); i++) A.push_back(1);
	}
	else
	{
		for (int i = 0; i < s.length(); i++) A.push_back((s[0] + 2) - '0');
	}

	vector<int> res = sub(A, B);

	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}