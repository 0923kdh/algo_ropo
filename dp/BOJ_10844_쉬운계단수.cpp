#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll ans, dp[101][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);                                                                                                                                                                 

    cin >> n;
    dp[1][0] = 0;
    for(int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
                dp[i][j] = dp[i-1][j+1] % 1000000000;
            else if(j == 9)
                dp[i][j] = dp[i-1][j-1] % 1000000000;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }

    for (int i = 0; i < 10; i++)
        ans = ans + dp[n][i];

    cout << ans % 1000000000;

    return 0;
}