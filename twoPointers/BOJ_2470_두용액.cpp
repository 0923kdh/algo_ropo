#include<bits/stdc++.h>

using namespace std;

int n, arr[100000], ans[2], minValue = INT_MAX;

void sol()
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int tempSum = arr[left] + arr[right];
		if (minValue > abs(tempSum))
		{
			minValue = abs(tempSum);
			ans[0] = left;
			ans[1] = right;
		}

		if (tempSum > 0)
			right--;
		else
			left++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	sol();

	cout << arr[ans[0]] << " " << arr[ans[1]] << "\n";

	return 0;
}