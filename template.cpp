//快读模板 fast read
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-')w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

inline void write(long long a)
{
	if (a > 9) write(a / 10);
	putchar(a % 10 + '0');
}

//数组离散化 discrete array
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

//利用hash判重边 edge de-duplication
//a，b表示起点终点
long long hash = a * 1000000ll + b;
if (a != b && !S.count(hash))
{
	add_edge(a, b);
	S.insert(hash);
}


//hash pair
struct hash_pair
{
	template<class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};
