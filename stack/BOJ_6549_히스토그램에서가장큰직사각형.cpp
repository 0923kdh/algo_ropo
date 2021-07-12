#include <iostream>
#include <stack>

using namespace std;

long long a[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	while(true) {
		cin >> n;
		if(n == 0)
			break;
		
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long ans = 0;
		stack<long long> s;
		for(int i = 0; i < n; i++) {
			int left = i;
			while(s.size() && a[s.top()] > a[i]) {
				long long height = a[s.top()];
				s.pop();
				long long width = i;
				if(s.size()) {
					width = (i - s.top() - 1);
				}
				ans = max(ans, width * height);
			}
			s.push(i);
		}

		while(s.size()) {
			long long height = a[s.top()];
			s.pop();
			long long width = n;
			if(s.size()) {
				width = n - s.top() - 1;
			}
			ans = max(ans, width * height);
		}
		cout << ans << "\n";
	}
    
	return 0;
}