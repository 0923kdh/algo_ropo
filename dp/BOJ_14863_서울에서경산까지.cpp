#include<bits/stdc++.h>

using namespace std;

struct Info
{
	int time, pay;
};
Info a[101], b[101];

int n, k, dp[101][100001];

int go(int here, int time)
{
	if (here == n)
		return 0;

	int& ret = dp[here][time];
	if (ret)
		return ret;

	ret = -1e6;
	if (time - a[here].time >= 0)
	{
		ret = max(ret, go(here + 1, time - a[here].time) + a[here].pay);
	}

	if (time - b[here].time >= 0)
	{
		ret = max(ret, go(here + 1, time - b[here].time) + b[here].pay);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].time >> a[i].pay >> b[i].time >> b[i].pay;
	}

	cout << go(0, k) << "\n";

	return 0;
}
