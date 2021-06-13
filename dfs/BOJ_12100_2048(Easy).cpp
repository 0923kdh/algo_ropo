#include<bits/stdc++.h>

using namespace std;

int board[20][20], n, answer;

void shift(int num)
{
	queue<int> q;

	switch (num)
	{
	case 0:
	{
		for (int col = 0; col < n; col++)
		{
			for (int row = 0; row < n; row++)
			{
				if (board[row][col] != 0)
				{
					q.push(board[row][col]);
					board[row][col] = 0;
				}
			}

			int idx = 0;
			while (!q.empty())
			{
				int block = q.front();
				q.pop();

				if (board[idx][col] == 0)
					board[idx][col] = block;
				else if (board[idx][col] == block)
				{
					board[idx][col] *= 2;
					idx++;
				}
				else
					board[++idx][col] = block;
			}
		}
		break;
	}
	case 1: 
	{
		for (int row = 0; row < n; row++)
		{
			for (int col = n - 1; col >= 0; col--)
			{
				if (board[row][col] != 0)
				{
					q.push(board[row][col]);
					board[row][col] = 0;
				}
			}

			int idx = n - 1;
			while (!q.empty())
			{
				int block = q.front();
				q.pop();

				if (board[row][idx] == 0)
					board[row][idx] = block;
				else if (board[row][idx] == block)
				{
					board[row][idx] *= 2;
					idx--;
				}
				else
					board[row][--idx] = block;
			}
		}
		break;
	}
	case 2:
	{
		for (int col = 0; col < n; col++)
		{
			for (int row = n - 1; row >= 0; row--)
			{
				if (board[row][col] != 0)
				{
					q.push(board[row][col]);
					board[row][col] = 0;
				}
			}
			int idx = n - 1;
			while (!q.empty())
			{
				int block = q.front();
				q.pop();

				if (board[idx][col] == 0)
					board[idx][col] = block;
				else if (board[idx][col] == block)
				{
					board[idx][col] *= 2;
					idx--;
				}
				else
					board[--idx][col] = block;
			}
		}
		break;
	}
	case 3:
	{
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (board[row][col] != 0)
				{
					q.push(board[row][col]);
					board[row][col] = 0;
				}
			}
			int idx = 0;
			while (!q.empty())
			{
				int block = q.front();
				q.pop();

				if (board[row][idx] == 0)
					board[row][idx] = block;
				else if (board[row][idx] == block)
				{
					board[row][idx] *= 2;
					idx++;
				}
				else
					board[row][++idx] = block;
			}
		}
		break;
	}

	default:
		break;
	}
}

void dfs(int num)
{
	if (num == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				answer = max(answer, board[i][j]);
			}
		}

		return;
	}

	int temp[20][20];
	memcpy(temp, board, sizeof(board));

	for (int i = 0; i < 4; i++)
	{
		shift(i);
		dfs(num+1);
		memcpy(board, temp, sizeof(board));
	}
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	dfs(0);
	cout << answer << "\n";

	return 0;
}