#include <bits/stdc++.h>

using namespace std;

int deleteRockCnt;
vector<int> temp;

bool check(int mid) {
    
    int cnt = 0, tempValue = temp[0];
    for(int i = 1; i < temp.size(); i++) {
        int dis = temp[i] - tempValue;
        if(mid <= dis) {
            tempValue = temp[i];
        } else {
            cnt++;
        }
    }

    return deleteRockCnt < cnt;
}

int solution(int distance, vector<int> rocks, int n) {
    
    deleteRockCnt = n;
    temp = rocks;
    temp.push_back(0);
    temp.push_back(distance);
    sort(temp.begin(), temp.end());
 
    int ans = 0, lo = 0, hi = temp[temp.size()-1];
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) {
            hi = mid - 1;    
            ans = hi;
        } else {   
            lo = mid + 1;
        }      
    }
    
    return ans;
}