#include<bits/stdc++.h>

using namespace std;

int n, dp[101], hp[101], happy[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> hp[i];

	for (int i = 0; i < n; i++)
		cin >> happy[i];

	for (int i = 0; i < n; i++) 
	{
		for (int j = 100; j > hp[i]; j--)
		{
			dp[j] = std::max(dp[j], dp[j - hp[i]] + happy[i]);
		}
	}

	cout << dp[100] << "\n";
	return 0;
}

