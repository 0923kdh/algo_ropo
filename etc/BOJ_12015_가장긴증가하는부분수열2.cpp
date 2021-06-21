#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto it = lower_bound(v.begin(), v.end(), num);
        if(it == v.end()) {
            v.push_back(num);
        } else {
            *it = num;
        }
    }

    cout << v.size() << "\n";

	return 0;
}