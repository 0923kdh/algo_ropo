#include<bits/stdc++.h>

using namespace std;

int n, m, arr[9], visited[9];
vector<int> v;

void dfs(int num)
{
	if (num == m)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;

		visited[i] = 1;
		v.push_back(arr[i]);
		dfs(num + 1);
		v.pop_back();
		visited[i] = 0;
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

	dfs(0);
	return 0;
}