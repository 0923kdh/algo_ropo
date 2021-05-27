#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m, arr[200001], pSum[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++)
    {
        pSum[i] = pSum[i-1] + arr[i];
    }

    map<int, int> cnt;
    cnt[0] = 1;
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        //arr[j] + ... + arr[i] == s[i] - s[j-1]
        //pSum[i] - s[j-1] == m
        //s[j-1] = s[i] - m (j - 1 < i)
        ans += cnt[pSum[i]-m];
        cnt[pSum[i]] += 1;
    }
    
    cout << ans << '\n';

    return 0;
}