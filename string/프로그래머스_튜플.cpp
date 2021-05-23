#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v(100000);

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    string tempString = "";
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == ',' || i == s.size() - 2)
        {
            v[stoi(tempString)].first = stoi(tempString);
            v[stoi(tempString)].second += 1;
            tempString.clear();
        }

        if (isdigit(s[i]) != 0)
        {
            tempString += s[i];
        }
    }

    sort(v.begin(), v.end(), compare);

    vector<int> answer;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == 0)
            break;

        answer.push_back(v[i].first);
    }

    return answer;
}