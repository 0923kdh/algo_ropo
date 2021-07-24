#include <vector>
#include <cmath>

using namespace std;

const int MAX_NUM = 50000;

int s, ans, prime[MAX_NUM +1];
vector<int> v;

void eratos() {
    for(int i = 2;i <= MAX_NUM; i++)
        prime[i] = 1;
    for(int i = 2;i <= sqrt(MAX_NUM); i++){
        if(prime[i] == 0)
            continue;
        for(int j = i*i; j <= MAX_NUM; j += i)
            prime[j]=0;
    }
}

void go(int nextIndex, int cnt, int sum) {
    if(cnt == 3) {
        if(prime[sum])
            ans++;
        return;
    } 
    for(int i = nextIndex; i < s; i++) {
        go(i + 1, cnt + 1, sum + v[i]);
    }
}

int solution(vector<int> nums) {
    v = nums;
    s = nums.size();
    eratos();
    go(0, 0, 0);
    return ans;
}