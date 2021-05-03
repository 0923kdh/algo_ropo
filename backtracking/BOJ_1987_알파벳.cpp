#include<bits/stdc++.h>

using namespace std;

int r, c, answer = 1, alphabet[26], dy[4] = { -1, 0 , 1, 0 }, dx[4] = { 0, 1, 0, -1 };
char arr[30][30];

void input()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}
}

int go(int y, int x, int num)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			continue;

		if (alphabet[arr[ny][nx] - 'A'])
			continue;

		alphabet[arr[ny][nx] - 'A'] = 1;
		answer = max(answer, go(ny, nx, num + 1));
		alphabet[arr[ny][nx] - 'A'] = 0;
	}

	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	alphabet[arr[0][0] - 'A'] = 1;
	go(0, 0, 1);
	cout << answer << "\n";
	return 0;
}