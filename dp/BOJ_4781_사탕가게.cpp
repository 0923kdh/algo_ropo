#include<bits/stdc++.h>

using namespace std;

int n, c, dp[10001];
double m, p;
pair<int, int> candy[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			cin >> c >> p;
			candy[i] = make_pair(c, (int)(p * 100 + 0.5));
		}

		int money = (int)(m * 100 + 0.5);
		for (int i = 0; i < n; i++)
		{
			for (int j = candy[i].second; j <= money; j++)
			{
				dp[j] = max(dp[j], dp[j - candy[i].second] + candy[i].first);
			}
		}
		cout << dp[money] << "\n";
	}

	return 0;
}
