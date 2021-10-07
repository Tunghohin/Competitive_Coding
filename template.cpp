/*
快读模板 quick read

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-')w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

数组离散化 discrete array

vector<int> hash;
map<int, int> hashed;
sort(hash.begin(), hash.end());
int cnt = 0;
for (auto i : hash)
{
	if (!hashed.count(i))
	{
		hashed[i] = ++cnt;
	}
}

利用hash判重边 edge de-duplication

a，b表示起点终点
long long hash = a * 1000000ll + b;

if (a != b && !S.count(hash))
{
	add_edge(a, b);
	S.insert(hash);
}
*/
