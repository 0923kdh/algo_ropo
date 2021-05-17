#include<stdc++.h>

using namespace std;
const string MAX_STRING = "1111111111111111111111111111111111111111111111111111";

// 0 1 2 3 4 5 6 7 8 9
int n, num, a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[101];

string findMax(int num)
{
    string ans = "";
    if (num & 1) //홀수
    {
        ans += '7';
        num -= 3;
    }

    while (num)
    {
        ans += '1';
        num -= 2;
    }

    return ans;
}

string compare(string a, string b)
{
    if (a.size() < b.size())
        return a;

    if (a.size() > b.size())
        return b;

    return (a < b ? a : b);
}

string go(int count)
{
    //기저사례
    if (count == 0)
        return "";

    //메모이제이션
    string& ret = dp[count];
    if (ret != MAX_STRING)
        return ret;

    //로직
    for (int i = 0; i < 10; i++)
    {
        if (count - a[i] < 0)
            continue;

        ret = compare(ret, to_string(i) + go(count - a[i]));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    //1 == 52개
    for (int i = 0; i < n; i++)
    {
        fill(dp, dp + 101, MAX_STRING);
        cin >> num;
        go(num);
        cout << dp[num] << " " << findMax(num) << '\n';
    }

    return 0;
}