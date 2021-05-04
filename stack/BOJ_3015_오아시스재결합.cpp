#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, height, answer;
stack<pair<ll, ll>> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> height;
		int  cnt = 1;
		while (s.size() && (s.top().first <= height))
		{
			answer += s.top().second;
			if (s.top().first == height)
			{
				cnt = s.top().second + 1;
			}
			else
			{
				cnt = 1;
			}
			s.pop();
		}

		if (s.size())
			answer++;

		s.push({ height, cnt });
	}

	cout << answer << '\n';

	return 0;
}