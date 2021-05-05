#include <bits/stdc++.h>

using namespace std;

int x, sum, barLength = 64, cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x;
	while (x != sum)
	{
		if ((sum + barLength) <= x)
		{
			sum += barLength;
			cnt++;
		}
		barLength /= 2;
	}
	cout << cnt << '\n';
	return 0;
}