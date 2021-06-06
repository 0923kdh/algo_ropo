#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void go(string orderStr, int course, string combiStr, int index)
{
    if(combiStr.size() == course)
    {
        m[combiStr]++;
        return;
    }
    
    for(int i = index; i < orderStr.size(); i++)
    {
        go(orderStr, course, combiStr + orderStr[i], i + 1);    
    }
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;    
    for(int i = 0; i < course.size(); i++)
    {
        m.clear();
        for(int j = 0; j < orders.size(); j++)
        {
            if(orders[j].size() < course[i])
                continue;
            
            sort(orders[j].begin(), orders[j].end());      
            go(orders[j], course[i], "", 0);        
        }
        
        if(m.empty())
            continue;
        
        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), compare);
        
        int maxCnt = v[0].second;
        for(int j = 0; j < v.size(); j++)
        {
            if(maxCnt == 1 || v[j].second < maxCnt)
                break;
            
            answer.push_back(v[j].first);  
        }
    }
    
    sort(answer.begin(), answer.end());  
    return answer;
}