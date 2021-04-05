#include<bits/stdc++.h>

using namespace std;

int t, w, a[1001], dp[3][1004][31];

//go(현재 나무 위치, 떨어지는 초, 움직일 수 있는 횟수)
int go(int curTree, int curSecond, int cnt)
{
	//base case, 마지막 초
	if (curSecond == t)
		return 0;

	int& ans = dp[curTree][curSecond][cnt];
	if (ans != -1)
		return ans;

	//현재 Tree가 1 이면 nextTree는 2이고
	//현재 Tree가 1 이 아니면 nextTree는 1이다.
	int nextTree = (curTree == 1) ? 2 : 1;
	
	//움직일 수 있는 경우
	if (cnt < w)
	{
		//nextTree로 움직이는 경우와 curTree에 있는 경우의 max 값을 비교한다.
		ans = max(go(nextTree, curSecond+1, cnt+1) + (!(a[curSecond]==curTree)), 
			go(curTree, curSecond + 1, cnt) + (a[curSecond] == curTree));
	}
	else
	{
		ans = go(curTree, curSecond + 1, cnt) + (a[curSecond] == curTree);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
	}

	//dp size 만큼 -1로 초기화
	memset(dp, -1, sizeof(dp));
	cout << go(1, 0, 0) << "\n";

	return 0;
}

