/*
快读模板
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-')w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

利用hash判重边的trick
a，b表示起点终点
long long hash = a * 1000000ll + b;

if (a != b && !S.count(hash))
{
	add_edge(a, b);
	S.insert(hash);
}
*/