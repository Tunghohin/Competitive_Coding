#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	int T;
	cin >> T;

	while (T--)
	{
		int W, H;
		int x1, y1, x2, y2;
		int w, h;

		scanf("%d%d", &W, &H);
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d%d", &w, &h);

		int dist = 1e9;

		if (x2 - x1 + w <= W)
		{
			dist = min(dist, max(0, w - x1));
			dist = min(dist, max(0, x2 - W + w));
		}

		if (y2 - y1 + h <= H)
		{
			dist = min(dist, max(0, h - y1));
			dist = min(dist, max(0, y2 - H + h));
		}

		if (dist == 1e9) printf("%d\n", -1);

		else
		{
			printf("%.9lf\n", (double)dist);
		}
	}

	return 0;
}