#include<bits/stdc++.h>

using namespace std;
int n;
string str;
vector<string> v;

bool check(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty() == false)
                s.pop();
            else
            {
                // )인데 (가 없을때
                return false;
            }
        }
    }
    //stack에 괄호 남아있을때
    return s.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (check(str))
            v.push_back("YES");
        else
            v.push_back("NO");
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}