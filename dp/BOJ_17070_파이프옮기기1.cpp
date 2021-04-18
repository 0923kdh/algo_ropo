#include<bits/stdc++.h>

using namespace std;

int n, a[20][20], dp[20][20][3];
int dy[3] = { 0, 1, 1 }, dx[3] = { 1, 0, 1 };

int go(int y, int x, int dir)
{
	if (y == n - 1 && x == n - 1)
		return dp[y][x][dir] = 1;

	int& ans = dp[y][x][dir];
	if (ans != -1)
		return ans;

	ans = 0;
	for (int i = 0; i < 3; i++)
	{
		//45도 회전만 가능함
		//가로->세로 || 세로->가로 불가능
		if ((i == 0 && dir == 1) || (i == 1 && dir == 0))
			continue;

		//대각선인 경우 
		if (i == 2 && (a[y][x + 1] || a[y + 1][x]))
			continue;

		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx])
			continue;

		ans += go(ny, nx, i);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << go(0, 1, 0) << "\n";

	return 0;
}