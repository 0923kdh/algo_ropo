#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> profit;

void calculateProfit(string name, int money) {
    if(name == "-")
        return;
    
    int parentProfit = money * 0.1;
    profit[name] += (money - parentProfit);    
    if(parentProfit < 1)
        return;
    
    calculateProfit(parent[name], parentProfit);   
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {    
    for(int i = 0; i< enroll.size(); i++) {
        parent[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); i++) {
        calculateProfit(seller[i], amount[i]*100);
    }
    
    vector<int> answer;
    for(int i = 0; i< enroll.size(); i++) {
        answer.push_back(profit[enroll[i]]);
    }
    
    return answer;
}