#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, dp[31][31];

ll go(ll all, ll half)
{
	if (all == 0 && half == 0)
		return 1;

	if (dp[all][half])
		return dp[all][half];

	ll& ret = dp[all][half];
	if (all > 0)
		ret += go(all - 1, half + 1);
	if (half > 0)
		ret += go(all, half - 1);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		cout << go(n, 0) << "\n";
	}

	return 0;
}
