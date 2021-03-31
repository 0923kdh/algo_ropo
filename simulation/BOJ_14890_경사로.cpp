#include<bits/stdc++.h>

using namespace std;

int n, l, answer, isFlatRoad, board[100][100], visited[100][100];

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

bool checkRoad(int& y, int& x)
{
	int cur = board[y][x];
	int next = board[y][x + 1];

	//차이가 2 이상날때는 지나갈 수 없다.
	if (abs(board[y][x] - board[y][x + 1]) > 1)
		return false;

	//평평한 길은 일단 지나간다.
	if (board[y][x] - board[y][x + 1] == 0)
		return true;

	//높은 경사로 //오른쪽이 더 큰 경우
	if (board[y][x] - board[y][x + 1] == -1)
	{
		for (int i = 0; i < l; i++)
		{
			if (visited[y][x - i])
				return false;
		}

		for (int i = 1; i < l; i++)
		{
			if (x - i < 0)
				return false;

			if (board[y][x] - board[y][x - i] != 0)
				return false;
		}
	}
	//낮은 경사로 //왼쪽이 더 큰 경우
	else if (board[y][x] - board[y][x + 1] == 1)
	{
		for (int i = 1; i <= l; i++)
		{
			if (x + i >= n)
				return false;

			if (board[y][x + i] - board[y][x + i + 1] != 0)
				return false;

			visited[y][x + i] = 1;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	//row 체크
	cout << "row" << "\n";
	for (int i = 0; i < n; i++)
	{
		bool isRoad = true;
		for (int j = 0; j < n - 1; j++)
		{
			if (checkRoad(i, j) == false)
			{
				cout << i << " : false" << "\n";
				isRoad = false;
				break;
			}
		}

		if (isRoad)
		{
			cout << i << " : true" << "\n";
			answer++;
		}
	}

	//col 체크
	cout << "col" << "\n";
	for (int i = 0; i < n; i++)
	{
		bool isRoad = true;
		for (int j = 0; j < n - 1; j++)
		{
			if (checkRoad(j, i) == false)
			{
				cout << i << " : false" << "\n";
				isRoad = false;
				break;
			}
		}

		if (isRoad)
		{
			cout << i << " : true" << "\n";
			answer++;
		}

	}

	cout << answer << "\n";

	return 0;
}
