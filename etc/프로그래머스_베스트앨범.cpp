#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> answer;
map<string, int> sum;
map<string, vector<pair<int, int>>> playList;

bool compare1(pair<string, int> p1, pair<string, int> p2) {
    if(p1.second > p2.second) 
        return true;
    
    return false;
}

bool compare2(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second > p2.second) 
        return true;
    
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    for(int i = 0; i < genres.size(); i ++) {
        sum[genres[i]] += plays[i];
        playList[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> v(sum.begin(), sum.end());
    sort(v.begin(), v.end(), compare1);
 
    vector<int> answer;
    for(int i = 0 ; i < v.size(); i++) {
        sort(playList[v[i].first].begin(), playList[v[i].first].end(), compare2);
        for(int j = 0; j < playList[v[i].first].size(); j++) {
            if(j >=2)
                break;
            answer.push_back(playList[v[i].first][j].first);
        }         
    }
  
    return answer;
}