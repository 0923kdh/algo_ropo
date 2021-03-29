#include<bits/stdc++.h>

using namespace std;

struct Fish
{
	int y, x, dist;
};

struct compare
{
	bool operator()(Fish a, Fish b)
	{
		if (a.dist == b.dist)
		{
			if (a.y == b.y)
			{
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};

int n, answer, dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 }, board[20][20], visited[20][20];
queue<Fish> q;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				//y, x, dist 
				q.push({ i, j, 0 });
				visited[i][j] = 1;
				board[i][j] = 0;
			}
		}
	}
}

void bfs()
{
	int size = 2;
	int eatFish = 0;
	int time = 0;
	while (true)
	{
		//먹을 수 있는 물고기 저장하는 우선순위 큐
		priority_queue<Fish, vector<Fish>, compare> pq;
		while (q.size())
		{
			Fish curFish = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = curFish.y + dy[i];
				int nx = curFish.x + dx[i];

				//경계 체크
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
					continue;

				//본인보다 작은 물고기만 먹을 수 있다.
				if (board[ny][nx] > size)
					continue;

				q.push({ ny, nx, curFish.dist + 1 });
				visited[ny][nx] = 1;

				if (board[ny][nx] < size && board[ny][nx] != 0)
				{
					pq.push({ ny, nx, curFish.dist + 1 });
				}
			}
		}

		fill(&visited[0][0], &visited[0][0] + 20 * 20, 0);

		if (pq.size())
		{
			auto cur = pq.top();
			pq.pop();
			board[cur.y][cur.x] = 0;
			eatFish++;
			time = cur.dist;
			q.push({ cur.y, cur.x, cur.dist });
			visited[cur.y][cur.x] = true;
		}
		else
		{
			answer = time;
			break;
		}

		if (eatFish == size)
		{
			size++;
			eatFish = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	bfs();
	cout << answer << "\n";

	return 0;
}