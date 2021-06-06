#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;
char _map[1004][1004];
int n, m, sx, sy, dx[4] = { 0, 1, 0,-1 }, dy[4] = { -1, 0, 1, 0 }, ret;
int fire_check[1004][1004], person_check[1004][1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	queue<pair<int, int>> q;
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> _map[i][j];
			if (_map[i][j] == 'F')
			{
				//불의 첫 시작 지점
				fire_check[i][j] = 1;
				q.push({ i,j });
			}

			if (_map[i][j] == 'J')
			{
				sy = i;
				sx = j;
			}
		}
	}

	//불 최단거리
	while (!q.empty()) 
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if ((1 <= ny && ny <= n && 1 <= nx && nx <= m) == false)
				continue;

			//방문한 정점이거나 벽이면 continue
			if (fire_check[ny][nx] != INF || _map[ny][nx] == '#') 
				continue;

			//불이 갈 수 있는 곳까지 도달
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	person_check[sy][sx] = 1;
	q.push({ sy,sx });
	while (!q.empty()) 
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//지훈이가 가장자리에 도달 = 빠져나옴
		if (x == m || y == n || x == 1 || y == 1) 
		{
			//최단거리
			ret = person_check[y][x];
			break;
		}

		for (int i = 0; i < 4; i++) 
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if ((1 <= ny && ny <= n && 1 <= nx && nx <= m) == false)
				continue;

			//이미 방문했거나 벽이거나
			if (person_check[ny][nx] || _map[ny][nx] == '#') 
				continue;

			//불의 최단거리보다 지훈이의 최단거리가 같거나 크면 탈출할 수 없는 지점
			if (fire_check[ny][nx] <= person_check[y][x] + 1) 
				continue;

			//이동할 수 있는 곳까지 도달
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	if (ret != 0) 
		cout << ret << "\n";
	else 
		cout << "IMPOSSIBLE \n";

	return 0;
}