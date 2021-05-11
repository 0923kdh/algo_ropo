#include<bits/stdc++.h>

using namespace std;

int t, n, num;
string p;
deque<int> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> p;
        cin >> n;
        string s;
        cin >> s;
        int x = 0;
        for (char c : s)
        {
            if (c == '[' || c == ']')
                continue;

            if (c >= '0' && c <= '9')
                x = x * 10 + c - '0';
            else
            {
                if (x > 0)
                    d.push_back(x);
                x = 0;
            }
        }

        if (x > 0)
            d.push_back(x);

        bool reverseString = false;
        bool isError = false;
        for (char c : p)
        {
            if (c == 'R')
            {
                reverseString = (reverseString == false) ? true : false;
                continue;
            }

            if (d.empty())
            {
                isError = true;
                break;
            }

            if (reverseString)
            {
                d.pop_back();
            }
            else
            {
                d.pop_front();
            }
        }

        if (isError)
        {
            cout << "error" << '\n';
        }
        else
        {
            int size = d.size();
            string str = "[";
            for (int j = 0; j < size; j++)
            {
                if (reverseString)
                {
                    str += to_string(d.back());
                    d.pop_back();
                }
                else
                {
                    str += to_string(d.front());
                    d.pop_front();
                }

                if (j != size - 1)
                    str += ",";
            }
            str += "]";
            cout << str << '\n';
        }
    }

    return 0;
}