#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	ll n = 0.0;
	while (cin >> n)
	{
		ll m = 1.0;
		int digits = 1;
		while ((m % n) != 0)
		{
			m %= n;
			m = m * 10 + 1;
			//m = (m * 10) % n + 1;
			digits++;
		}
		cout << digits << "\n";
	}

	return 0;
}