#include<bits/stdc++.h>

using namespace std;

int n, m, answer = -987654321, board[500][500], visited[500][500];
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
int sx[4][3] = { { 0, 1, 0 }, { -1, 0, 1 }, { 0, 0, -1 }, { -1, 0, 1 } };
int sy[4][3] = { { -1, 0, 1 }, { 0, 1, 0 }, { -1, 1, 0 }, { 0, -1, 0 } };

void go(int y, int x, int cnt, int sum)
{
	if (cnt == 3)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
			continue;

		visited[ny][nx] = 1;
		go(ny, nx, cnt + 1, sum + board[ny][nx]);
		visited[ny][nx] = 0;
	}
}

void shapeCheck(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int sum = board[y][x];
		for (int j = 0; j < 3; j++)
		{
			int ny = y + sy[i][j];
			int nx = x + sx[i][j];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				sum = 0;
				break;
			}

			sum += board[ny][nx];
		}
		answer = max(answer, sum);
	}

}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			go(i, j, 0, board[i][j]);
			visited[i][j] = 0;
			shapeCheck(i, j);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	cout << answer << "\n";

	return 0;
}