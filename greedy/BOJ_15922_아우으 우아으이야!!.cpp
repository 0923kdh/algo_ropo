#include<bits/stdc++.h>

using namespace std;

int n, answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int start = -1e9-1, end = -1e9-1;

	for (int i = 0; i < n; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		//겹치는 부분이 없음
		if (num1 > end)
		{
			answer += end - start;
			start = num1;
			end = num2;
		}
		else
		{
			end = max(end, num2);
		}
	}

	answer += end - start;

	cout << answer << "\n";
	return 0;
}