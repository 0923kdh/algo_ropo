#include <string>
#include <vector>

using namespace std;

bool check(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else
            cnt--;

        if (cnt < 0)
            return false;
    }

    return true;
}

string tranformString(string str)
{
    if (str.empty())
        return "";

    string u, v;
    int left = 0, right = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == '(')
            left++;
        else
            right++;

        if (left == right)
        {
            u = str.substr(0, i + 1);
            v = str.substr(i + 1);
            break;
        }
    }

    if (check(u))
        return u + tranformString(v);
    else
    {
        string temp = "(";
        temp += tranformString(v) + ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] == '(')
                temp += ')';
            else
                temp += '(';
        }
        return temp;
    }
}

string solution(string p)
{
    if (check(p))
        return p;

    return tranformString(p);
}