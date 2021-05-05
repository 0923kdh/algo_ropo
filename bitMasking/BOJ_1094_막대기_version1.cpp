#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << bitset<8>(n).count() << '\n';
	return 0;
}