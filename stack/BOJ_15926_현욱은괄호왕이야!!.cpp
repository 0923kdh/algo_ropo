#include<bits/stdc++.h>

using namespace std;

int n, answer, temp, cnt[200001];
string str;
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else if (s.size())
        {
            cnt[i] = cnt[s.top()] = 1;
            s.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cnt[i])
        {
            temp++;
            answer = max(answer, temp);
        }
        else
        {
            temp = 0;
        }
    }

    cout << answer << '\n';
    return 0;
}