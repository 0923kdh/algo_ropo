#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, h, result = 987654321;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h;
    vector<int> bottom(n/2), top(n/2);

    for (int i = 0; i < n/2; i++) {
        cin >> bottom[i] >> top[i];
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int cnt = 1;
    for (int i = 1; i <= h; i++)
    {
        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
        temp += top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin());

        if(result < temp)
            continue;

        if (result == temp) {
            cnt++;
        } else {
            result = temp;
            cnt = 1;
        }
    }

    cout << result << " " << cnt << "\n";

    return 0;
}