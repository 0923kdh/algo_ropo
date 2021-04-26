#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    set<string> s;
    char prev = words[0].front();
    int people = 0, cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        auto iter = s.find(words[i]);
        if (iter == s.end() && prev == words[i].front())
        {
            s.insert(words[i]);
            prev = words[i].back();
            continue;
        }

        people = (i % n) + 1;
        cnt = i / n + 1;
        break;
    }

    answer.push_back(people);
    answer.push_back(cnt);
    return answer;
}