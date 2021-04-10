#include<bits/stdc++.h>

using namespace std;

int n, m, arr[9], visited[9];

void dfs(int num)
{
	if (num == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		arr[num] = i;
		dfs(num + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0);
	return 0;
}