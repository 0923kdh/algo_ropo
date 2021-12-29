#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; ++i) {
        long long quotient = i / n;
        long long remainder = i % n;
        if(quotient >= remainder){
            answer.push_back(quotient+1);
        }else{
            long long gap = remainder - quotient;
            answer.push_back(quotient+1+gap);
        }
    }
    return answer;
}