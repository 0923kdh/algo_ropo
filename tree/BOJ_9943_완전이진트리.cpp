#include<bits/stdc++.h>

using namespace std;

vector<int> ret[11];
int n, a[1030];

void go(int start, int end, int depth)
{
	if (start > end)
		return;

	// 마지막 depth일 경우
	if (start == end)
	{
		ret[depth].push_back(a[start]);
		return;
	}

	int mid = (start + end) / 2;
	ret[depth].push_back(a[mid]);
	go(start, mid - 1, depth + 1);
	go(mid + 1, end, depth + 1);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int end = (int)pow(2, n) - 1;
	for (int i = 0; i < end; i++)
	{
		cin >> a[i];
	}

	go(0, end, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j : ret[i])
		{
			cout << j << " ";
		}
		cout << "\n";
	}

	return 0;
}