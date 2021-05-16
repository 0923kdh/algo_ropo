#include<bits/stdc++.h>

using namespace std;

int n, l, board1[100][100], board2[100][100];

void input()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board1[i][j];
			board2[j][i] = board1[i][j];
		}
	}
}

int go(int arr[][100])
{
	int asnwer = 0;
	for (int i = 0; i < n; i++)
	{
		int len = 1;
		bool isSucceed = true;
		for (int j = 0; j < n - 1; j++)
		{
			if (abs(arr[i][j] - arr[i][j + 1]) > 1)
			{
				isSucceed = false;
				break;
			}

			if (arr[i][j] == arr[i][j + 1])
				len++;
			//낮은곳->높은곳
			else if (arr[i][j + 1] - arr[i][j] == 1)
			{
				if (len >= l)
					len = 1;
				else
				{
					isSucceed = false;
					break;
				}
			}
			//높은곳->낮은곳
			else if (arr[i][j] - arr[i][j + 1] == 1)
			{
				if (j + 1 + l > n)
				{
					isSucceed = false;
					break;
				}

				int height = arr[i][j + 1];
				for (int k = j + 1; k < j + 1 + l; k++)
				{
					if (height != arr[i][k])
					{
						isSucceed = false;
						break;
					}
				}

				j += l - 1;
				len = 0;
			}
		}

		if (isSucceed)
			asnwer++;
	}

	return asnwer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	cout << go(board1) + go(board2) << '\n';

	return 0;
}