#include<bits/stdc++.h>

using namespace std;

int n, m, arr[9], visited[9];

void dfs(int num, int next)
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

	for (int i = next; i <= n; i++)
	{
		arr[num] = i;
		dfs(num + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0, 1);
	return 0;
}