#include<bits/stdc++.h>

using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	bool isSucceed = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (i < s.size() - 1 && (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka"))
			i += 1;
		else if (i < s.size() - 2 && (s.substr(i, 3) == "chu"))
			i += 2;
		else
		{
			isSucceed = false;
			break;
		}
	}

	if (isSucceed)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
	return 0;
}