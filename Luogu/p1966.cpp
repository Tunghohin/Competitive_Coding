#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1e8 - 3;

int a[100010];
int b[100010];

map<int, int> mp;

int find(int x, vector<int> &v)
{
	return (int)(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}

int tmp[100010];
long long merge_find(int l,int r)
{
    if (l>=r) return 0;

    int mid = (l+r) >> 1;

    long long cnt=(merge_find(l,mid)+merge_find(mid+1,r)) % MOD;

    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) 
        {
            tmp[k++]=a[i++];
        }
        else 
        {
            tmp[k++]=a[j++];
            cnt= (((cnt + mid) % MOD - i + MOD) % MOD + 1) % MOD;
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for (int i=l,j=0;i<=r;i++,j++)
    {
        a[i]=tmp[j];
    }
    return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> hash_a, hash_b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		hash_a.push_back(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		hash_b.push_back(b[i]);
	}

	sort(hash_a.begin(), hash_a.end());
	sort(hash_b.begin(), hash_b.end());
	hash_a.erase(unique(hash_a.begin(), hash_a.end()), hash_a.end());
	hash_b.erase(unique(hash_b.begin(), hash_b.end()), hash_b.end());

	for (int i = 1; i <= n; i++) a[i] = find(a[i], hash_a);
	for (int i = 1; i <= n; i++) b[i] = find(b[i], hash_b);

	for (int i = 1; i <= n; i++)
	{
		mp[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) a[i] = mp[a[i]];

	cout << merge_find(1, n) % MOD;
}