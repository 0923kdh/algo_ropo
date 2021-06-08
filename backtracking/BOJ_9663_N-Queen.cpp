#include<bits/stdc++.h>

using namespace std;

int n, m, arr[10], ans[10], visited[10];

void go(int cur, int next) 
{
	if (cur == m) 
	{
		for (int i = 0; i < m; i++) 
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = next; i < n; i++) 
	{
		if (visited[i])
			continue;

		visited[i] = true;
		ans[cur] = arr[i];
		go(cur + 1, i + 1);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	go(0, 0);

	return 0;
}