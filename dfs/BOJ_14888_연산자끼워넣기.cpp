#include <iostream>

using namespace std;

const int MAX = 1000000001;

int n, minNum = MAX, maxNum = -MAX, num[12], oper[4];

void go(int plus, int minus, int multiply, int divide, int cnt, int sum)
{
    if(cnt == n)
    {
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
    }
    
    if(plus > 0)
        go(plus-1, minus, multiply, divide, cnt+1, sum + num[cnt]);
    if(minus > 0)
        go(plus, minus-1, multiply, divide, cnt+1, sum - num[cnt]);
    if(multiply > 0)
        go(plus, minus, multiply-1, divide, cnt+1, sum * num[cnt]);
    if(divide > 0)
        go(plus, minus, multiply, divide-1, cnt+1, sum / num[cnt]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);                                                                                                                                                                 

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    
    for(int i = 0; i < 4; i++)
        cin >> oper[i];

    go(oper[0], oper[1], oper[2], oper[3], 1, num[0]);

    cout << maxNum << "\n";
    cout << minNum << "\n";
    
    return 0;
}