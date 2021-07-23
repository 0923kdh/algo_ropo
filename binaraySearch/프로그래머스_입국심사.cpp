#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll peopleCnt, maxTime, ans; 
vector<ll> temp;

bool check(ll mid) {
    
    ll tempPeopleCnt = 0;
    for(int i = 0; i < temp.size(); i++) {
        tempPeopleCnt += (mid / temp[i]);
    }
    
    return peopleCnt <= tempPeopleCnt;
    
}

long long solution(int n, vector<int> times) {

    peopleCnt = (ll)n;
    for(int i = 0; i < times.size(); i++) {
        maxTime = max(maxTime, (ll)times[i]);
        temp.push_back((ll)times[i]);
    }
    
    ll lo = 0, hi = maxTime * peopleCnt;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
            ans = lo;
        }
    }
    
    return ans;
}