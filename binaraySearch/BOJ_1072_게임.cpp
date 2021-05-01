#include<bits/stdc++.h>

using namespace std;

long long x, y, initWinningRate, ans;

bool isIncreaseWinningRate(int runCount)
{
    long long tempWinningRate = (y + runCount) * 100 / (x + runCount);
    if (tempWinningRate > initWinningRate)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;
    initWinningRate = (y * 100) / x;
    long long lo = 0, hi = 1000000000, runCount;
    while (lo <= hi)
    {
        runCount = (lo + hi) / 2;
        if (isIncreaseWinningRate(runCount))
        {
            ans = runCount;
            hi = runCount - 1;
        }
        else
        {
            lo = runCount + 1;
        }
    }

    cout << (ans ? ans : -1) << "\n";

    return 0;
}