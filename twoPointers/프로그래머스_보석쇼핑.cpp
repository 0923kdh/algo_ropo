#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer;
    map<string, int> m;
    set<string> s(gems.begin(), gems.end());
    
    int min = 0, start = 0, end = 0;
    for(const auto& gem : gems)
    {
        m[gem]++;
        if(m.size() == s.size())
            break;
        end++;
    }
    
    min = end - start;
    answer.push_back(start+1);
    answer.push_back(end+1);
    
    while(end < gems.size())
    {
        string jewName = gems[start];
        m[jewName]--;
        start++;
        
        if(m[jewName] == 0)
        {
            end++;
            for(int i = end; i < gems.size(); i++)
            {
                m[gems[i]]++;
                if(jewName == gems[i])
                    break;
                end++;
            }
        }

        if(min > end - start)
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
            min = end - start;
        }
    }
    
    return answer;
}