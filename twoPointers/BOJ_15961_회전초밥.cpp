#include<bits/stdc++.h>

using namespace std;

int arr[3000001];
int chk[3001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int answer = 0;
	int total = 0;
	for (int i = 0; i < k; i++)
	{
		if (chk[arr[i]] == 0)
			total++;

		chk[arr[i]]++;
	}

	answer = max(answer, total);

	int lptr = 0;
	int rptr = k;

	while (1)
	{
		// 왼쪽 포인터 (빠진 음식)
		if (chk[arr[lptr]] == 1)
			total--;
		chk[arr[lptr]]--;

		// 오른쪽 포인터 (추가된 음식)
		if (chk[arr[rptr]] == 0)
			total++;
		chk[arr[rptr]]++;

		// 쿠폰에 해당하는 값이 없으면 +1
		if (chk[c] == 0)
			answer = max(answer, total + 1);
		else
			answer = max(answer, total);

		// 포인터 이동
		lptr = (lptr + 1) % n;
		rptr = (rptr + 1) % n;

		// 한바퀴 다돈경우
		if (lptr == 0) break;
	}
	cout << answer;
}