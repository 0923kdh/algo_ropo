#include <iostream>
#include <vector>

using namespace std;

int ans = -987654321, dp[100001][4];
vector<vector<int>> temp;

void go(int row, int col) {
    for(int i = 0; i < 4; i++) {
        if(i == col)
            continue;
       
        if(dp[row][col] < dp[row-1][i] + temp[row][col]) {
            dp[row][col] = dp[row-1][i] + temp[row][col];
        }
    }
}

int solution(vector<vector<int>> land)
{
    temp = land;
    for(int i = 0; i < 4; i++) {
        dp[0][i] = temp[0][i];
    }
    
    for(int i = 1; i < temp.size(); i++) {
        for(int j = 0; j < 4; j++) {
            go(i, j);
        }
    }
    
    for(int i = 0; i < 4; i++) {
        ans = max(ans, dp[temp.size()-1][i]);
    }

    return ans;
}