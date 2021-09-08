#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, index = 0, time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    while(index < jobs.size() || !pq.empty()) {
        if(jobs.size() > index && time >= jobs[index][0]){
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
            continue;
        }

        if(!pq.empty()){
            vector<int> temp = pq.top();
            time += temp[0];
            answer += time - temp[1];
            pq.pop();
        }else{
            time = jobs[index][0];
        }
    }
    return answer / jobs.size();
}