#include<stdc++.h>

using namespace std;

typedef long long ll;
ll s, c, cnt, sum, arr[1000000];

bool check(ll mid)
{
	ll quotient = 0;
	for (int i = 0; i < s; i++)
		quotient += arr[i] / mid;

	return quotient < c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> c;
	ll low = 0, high = 0;
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		high = max(high, arr[i]);
	}

	while (low <= high)
	{
		ll mid = (low + high) / (1LL * 2);
		if (check(mid))
		{
			high = mid - 1;
		}
		else
		{
			cnt = mid;
			low = mid + 1;
		}
	}

	cout << sum - (cnt * c) << "\n";
	return 0;
}

