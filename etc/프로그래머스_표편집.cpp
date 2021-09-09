#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {

    set<int> table;
    stack<int> history;

    for (int i = 0; i < n; ++i) {
        table.insert(i);
    }

    set<int>::iterator cur = table.find(k);
    for (string s : cmd) {
        char c = s[0];
        if(c == 'U') { //현재 칸에서 x 칸 위에 있는 행을 선택.
            int interval = stoi(s.substr(2));
            while(interval--) {
                cur = prev(cur);
            }
        } else if (c == 'D') { //현재 칸에서 x 칸 아래에 있는 행을 선택.
            int interval = stoi(s.substr(2));
            while(interval--){
                cur = next(cur);
            }
        } else if (c == 'C') { //현재 선택된 행 삭제, 바로 아래 행 선택, 삭제행이 마지막일 경우 바로 윗 행 선택
            history.push(*cur);
            cur = table.erase(cur);

            if(table.empty())
                continue;

            if(cur != table.end())
                continue;

            cur = prev(cur);
        } else { //가장 최근에 삭제된 행을 원래대로 복구, 선택되어 있는 행은 유지
            table.insert(history.top());
            history.pop();
        }
    }

    string answer(n, 'X');
    for(const auto& i : table) {
        answer[i] = 'O';
    }

    return answer;
}