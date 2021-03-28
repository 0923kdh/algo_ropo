#include<bits/stdc++.h>

using namespace std;

struct Robot
{
	int y, x, dir;
};

Robot robot;
int n, m, dir, cnt, board[50][50], visited[50][50];
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };

void input()
{
	cin >> n >> m;
	cin >> robot.y >> robot.x >> robot.dir;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			cin >> board[i][j];
		}
	}
}

//왼쪽방향에 청소되지 않은 공간이 있다면 왼쪽회전, 한칸 전진, 청소 => 왼쪽회전, 한칸 전진, 방문 처리
//왼쪽뱡향에 청소할 공간이 없다면 왼쪽회전 한번 더 => 왼쪽회전, 청소 가능 여부 확인, 왼쪽회전
//네방향 모두 청소되어있거나 벽인 경우, 뱡향 유지한채 후진 => 네번 회전 하면서 방문처리 체크, 벽 체크, 한칸 후진
//네방향 모두 청소되어있거나 벽이면서, 후진도 안됨 => 네번 회전하면서 방문처리 체크, 벽 체크, 한칸 후진 체크 후 종료

bool isBound(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= m || board[y][x] == 1)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	queue<Robot> q;
	q.push({ robot.y, robot.x, robot.dir });
	visited[robot.y][robot.x] = 1;
	cnt = 1;

	while (q.size())
	{
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().dir;
		q.pop();

		int ny = 0, nx = 0;
		bool isBack = true;
		for (int i = 0; i < 4; i++)
		{
			d = (d + 3) % 4;
			ny = y + dy[d];
			nx = x + dx[d];

			if (isBound(ny, nx))
				continue;

			//이미 청소가 되어있다. //벽이다.
			if (visited[ny][nx])
				continue;

			q.push({ ny , nx, d });
			visited[ny][nx] = 1;
			cnt++;
			isBack = false;
			break;
		}

		if (isBack)
		{
			int tempDir = (d + 2) % 4;
			ny = y + dy[tempDir];
			nx = x + dx[tempDir];
			
			if (isBound(ny, nx))
				continue;

			q.push({ ny , nx, d });
		}
	}

	cout << cnt << "\n";

	return 0;
}