#include<bits/stdc++.h>

using namespace std;

int n, l, answer, board[100][100];

void input()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
}

void checkRoad(queue<int> q)
{
	int prevHeight = q.front();
	q.pop();
	int flatRoad = 1;
	while (q.size())
	{
		int curHeight = q.front();

		//높이가 2이상 차이나면 길을 건널 수 없다.
		if (abs(prevHeight - curHeight) > 1)
			break;

		//내려가는 경우
		if (prevHeight - curHeight == 1)
		{
			prevHeight = curHeight;
			flatRoad = 1;
			q.pop();
			continue;
		}

		//올라가는 경우
		if (prevHeight - curHeight == -1)
		{
			if (flatRoad / l == 0)
				break;

			prevHeight = curHeight;
			flatRoad = 1;
			q.pop();
			continue;
		}

		if (abs(prevHeight - curHeight) == 0)
		{
			flatRoad++;
		}

		prevHeight = curHeight;
		q.pop();
	}

	if (q.empty())
		answer++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	//row 체크
	for (int i = 0; i < n; i++)
	{
		queue<int> q;
		for (int j = 0; j < n; j++)
		{
			q.push(board[i][j]);
		}
		checkRoad(q);
	}

	//col 체크
	for (int i = 0; i < n; i++)
	{
		queue<int> q;
		for (int j = 0; j < n; j++)
		{
			q.push(board[j][i]);
		}
		checkRoad(q);
	}

	cout << answer << "\n";

	return 0;
}
