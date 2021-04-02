#include<bits/stdc++.h>

using namespace std;

int n, m, answer, arr[100000];

bool checkBluraySize(int size)
{
	int tempSize = size;
	int cnt = 0;
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] > size) 
		{
			return false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (tempSize - arr[i] > 0)
		{
			tempSize -= arr[i];
		}
		else
		{
			tempSize = size - arr[i];
			cnt++;
		}
	}

	if (tempSize != size)
		cnt++;

	//cnt 가 작은 경우 
	//블루레이 개수가 작다 = 블루레이에 기록되는 크기가 크다 = size 가 크다
	//size 값을 줄인다.
	return cnt <= m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int pSum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		pSum += arr[i];
	}

	int low = 0, hi = pSum;
	while (low <= hi)
	{
		int size = (low + hi) / 2;
		if (checkBluraySize(size))
		{
			hi = size - 1;
			answer = size;
		}
		else
		{
			low = size + 1;
		}
	}

	cout << answer << "\n";

	return 0;
}