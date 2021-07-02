#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> v;
unordered_map<string, vector<int>> m; //query, score

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        if(temp == "and" || temp == "-") 
            continue;
        answer.push_back(temp);
    }
 
    return answer;
}

void makeCombi(vector<string> v) {
    for(int i = 1; i <= (1 << 4); i++) {
        string query;
        for(int j = 0; j < 4; j++) {
            if(i & (1 << j)) {
                query += v[j];
            }
        }
        
        if(query.empty())
            query = "onlyScore";

        m[query].push_back(stoi(v[4]));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i = 0; i < info.size(); i++) {
        vector<string> temp = split(info[i], ' ');
        makeCombi(temp);
    }
    
    for(auto& s : m) {
         sort(s.second.begin(), s.second.end());
    }

    for(const auto& q : query) {
        vector<string> temp = split(q, ' ');
        string tempQuery;
        for(int i = 0; i < temp.size() - 1; i++){
            tempQuery += temp[i];
        }
        
        if(tempQuery.empty())
            tempQuery = "onlyScore";

        vector<int> scores = m[tempQuery];
        if(scores.size()) {
            auto iter = lower_bound(scores.begin(), scores.end(), stoi(temp[temp.size()-1]));
            answer.push_back(scores.size() - (iter - scores.begin()));
        } else {
            answer.push_back(0);
        }
    }
    
    return answer;
}