#include<bits/stdc++.h>

using namespace std;

string s;
int n, m, answer = -987654321, arr[4][4], board[4][4];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = s[j] - '0';
		}
	}
}

void check()
{
	int sum = 0;
	//가로 체크
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
			{
				temp = temp * 10 + board[i][j];
			}
			else
			{
				sum += temp;
				temp = 0;
			}
		}
		sum += temp;
	}

	//세로 체크
	for (int i = 0; i < m; i++)
	{
		int temp = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == 0)
			{
				temp = temp * 10 + board[j][i];
			}
			else
			{
				sum += temp;
				temp = 0;
			}
		}
		sum += temp;
	}

	answer = max(answer, sum);
}

void go(int pos)
{
	if (pos > n * m - 1)
	{
		check();
		return;
	}

	int x = pos % n;
	int y = pos / n;

	arr[x][y] = 1;
	go(pos + 1);

	arr[x][y] = 0;
	go(pos + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	go(0);

	cout << answer << "\n";

	return 0;
}