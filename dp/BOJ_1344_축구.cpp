#include<bits/stdc++.h>

using namespace std;

const int n = 18;
double perA, perB, dp[20][20][20];

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

double go(int idx, int x, int y)
{
    if (idx == n)
        return isPrime(x) || isPrime(y) ? true : false;

    double& ret = dp[idx][x][y];
    if (ret > -0.5)
        return ret;

    ret = 0.0;
    ret += go(idx + 1, x + 1, y) * perA * (1 - perB);
    ret += go(idx + 1, x + 1, y + 1) * perA * perB;
    ret += go(idx + 1, x, y + 1) * (1 - perA) * perB;
    ret += go(idx + 1, x, y) * (1 - perA) * (1 - perB);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> perA >> perB;
    perA *= 0.01, perB *= 0.01;
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0) << "\n";

    return 0;
}