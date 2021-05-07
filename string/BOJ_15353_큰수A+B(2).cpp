#include <bits/stdc++.h>

using namespace std;

string a, b;

string add(string a, string b)
{
    int sum = 0;
    string ans = "";
    while (a.size() || b.size() || sum)
    {
        if (a.size())
        {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (b.size())
        {
            sum += b.back() - '0';
            b.pop_back();
        }

        ans += (sum % 10) + '0';
        sum /= 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    cin >> a >> b;
    cout << add(a, b) << '\n';

    return 0;
}