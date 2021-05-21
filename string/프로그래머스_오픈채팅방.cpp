#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<pair<string, pair<string, string>>> v;

void split(string s)
{
    stringstream ss(s);
    string temp;
    vector<string> tempString;

    while (getline(ss, temp, ' '))
    {
        tempString.push_back(temp);
    }

    if (tempString.size() < 3)
    {
        tempString.push_back("");
    }
    v.push_back({ tempString[0], { tempString[1],  tempString[2] } });
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userInfo;

    for (int i = 0; i < record.size(); i++)
    {
        split(record[i]);
        if (v[i].first.compare("Leave") == 0)
            continue;

        userInfo[v[i].second.first] = v[i].second.second;
    }

    for (int i = 0; i < record.size(); i++)
    {
        if (v[i].first.compare("Change") == 0)
            continue;

        auto iter = userInfo.find(v[i].second.first);
        if (iter == userInfo.end())
            continue;

        string s;
        if (v[i].first.compare("Enter") == 0)
        {
            s += iter->second;
            s += "님이 들어왔습니다.";
        }
        else
        {
            s += iter->second;
            s += "님이 나갔습니다.";
        }
        answer.push_back(s);
    }

    return answer;
}