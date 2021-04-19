#include<bits/stdc++.h>

using namespace std;

int n, m, answer, parent[1001];
vector<pair<int, pair<int, int>>> edge;

int getParent(int x)
{
	if (x == parent[x])
		return x;

	return parent[x] = getParent(parent[x]);
}

bool isSameParent(int x, int y)
{
	x = getParent(x);
	y = getParent(y);

	return x == y ? true : false;
}

void merge(int x, int y)
{
	x = getParent(x);
	y = getParent(y);

	if (x == y)
		return;

	if (x > y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, { a, b } });
	}

	sort(edge.begin(), edge.end());

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		if (isSameParent(edge[i].second.first, edge[i].second.second) == false)
		{
			merge(edge[i].second.first, edge[i].second.second);
			answer += edge[i].first;
		}
	}

	cout << answer << "\n";
	return 0;
}