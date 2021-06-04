#include<bits/stdc++.h>

using namespace std;
int num, arr[64][64];
string str;

void dfs(int a, int b, int num)
{
	if (num == 1)
	{
		cout << arr[a][b];
		return;
	}

	int temp = arr[a][b];
	bool isSameNum = true;
	for (int i = a; i < a + num; i++)
	{
		for (int j = b; j < b + num; j++)
		{
			if (temp != arr[i][j])
			{
				isSameNum = false;
				break;
			}
		}
	}

	if (isSameNum)
	{
		cout << temp;
	}
	else
	{
		int n = num / 2;
		cout << "(";
		dfs(a, b, n); //leftTop
		dfs(a, b + n, n); //rightTop
		dfs(a + n, b, n); //leftBottom
		dfs(a + n, b + n, n); //rightBotton
		cout << ")";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	dfs(0, 0, num);

	return 0;
}