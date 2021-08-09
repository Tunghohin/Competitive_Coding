#include <iostream>
#include <string>

using namespace std;

string a;
char p[5] = {'h', 'e', 'l', 'l', 'o'};

int main()
{
	getline(cin, a);
	int len = a.size();
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'h')
		{
			int cnt = 1;
			int k = 1;
			for (int j = i + 1; j < len; j++)
			{
				if (a[j] == p[k])
				{
					k++;
					if (k == 5)
					{
						printf("YES");
						exit(0);
					}
					continue;
				}
			}
			continue;
		}
	}
	printf("NO");
	return 0;
}
