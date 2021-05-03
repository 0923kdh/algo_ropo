#include <bits/stdc++.h>

using namespace std;

int n, arr[1000001], ans[1000001];
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (s.empty() == false && s.top() <= arr[i])
			s.pop();

		if (s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();

		s.push(arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}