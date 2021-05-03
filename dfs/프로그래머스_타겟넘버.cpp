#include <bits/stdc++.h>

using namespace std;

int answer, sum;
vector<int> v;

void dfs(int target, int index)
{
    if (index == v.size())
    {
        if (sum == target)
        {
            answer++;
        }
        return;
    }

    dfs(target + v[index], index + 1);
    dfs(target - v[index], index + 1);
}

int solution(vector<int> numbers, int target)
{
    sum = target;
    v = move(numbers);
    dfs(0, 0);
    return answer;
}