#include <bits/stdc++.h>

using namespace std;

int n, coin[21], answer = 987654321;
string s;

void checkingCoin()
{
    /*{
    i == 1 == 00000001
    i == 2 == 00000010
    i == 3 == 00000100
    i == 4 == 00001000
    i == 5 == 00010000
    ...

    checkingCoin을 처음 실행하게되면 아래와 같이 뒤집힌 상태이다.
    coin[1] == HHT == 110         ~coin[1] == TTH == 001
    coin[2] == THH == 011   =>    ~coin[2] == HTT == 100
    coin[3] == THT == 010         ~coin[3] == HTH == 101

    for(int j = 1; j <= n; j++)
        if(coin[j] & i)

    를 통해서 열단위로 동전을 셀 수 있게된다.

    i == 1, j == 1 이면 ~coin[1] == TTH == 001 에서 뒤에서 0번째인 1만 검출 == H
    i == 1, j == 2 이면 ~coin[2] == HTT == 100 에서 뒤에서 0번째인 0만 검출 == T
    i == 1, j == 3 이면 ~coin[3] == HTH == 101 에서 뒤에서 0번째인 1만 검출 == H
    즉, i == 1, 1 <= j <= 3 일때 T 1개, H 2개임을 알 수 있다.

    i == 2, j == 1 이면 ~coin[1] == TTH == 001 에서 뒤에서 1번째인 0만 검출 == T
    i == 2, j == 2 이면 ~coin[2] == HTT == 100 에서 뒤에서 1번째인 0만 검출 == T
    i == 2, j == 3 이면 ~coin[3] == HTH == 101 에서 뒤에서 1번째인 0만 검출 == T
    즉, i == 2, 1 <= j <= 3 일때 T 3개

    i == 3, j == 1 이면 ~coin[1] == TTH == 001 에서 뒤에서 2번째인 0만 검출 == T
    i == 3, j == 2 이면 ~coin[2] == HTT == 100 에서 뒤에서 2번째인 1만 검출 == H
    i == 3, j == 3 이면 ~coin[3] == HTH == 101 에서 뒤에서 2번째인 1만 검출 == H
    즉, i == 3, 1 <= j <= 3 일때 T 1개, H 2개임을 알 수 있다.

    해당 함수를 한번 실행하게 되면 T 개수와 H 개수를 알 수 있음.
    }*/
    int sum = 0;
    for (int i = 1; i <= (1 << (n - 1)); i *= 2)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (coin[j] & i)
                cnt++;
        }
        sum += min(cnt, n - cnt);
    }
    answer = min(answer, sum);
}

void go(int num)
{
    if (num == n + 1)
    {
        checkingCoin();
        return;
    }

    coin[num] = ~coin[num];
    go(num + 1);

    coin[num] = ~coin[num];
    go(num + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int value = 0;
        int index = n;
        for (int j = 0; j < s.size(); j++)
        {
            //T == 0 == 앞면, H == 1 == 뒷면
            index--;
            if (s[j] == 'T')
                continue;
            //(1 << j) 로 해줘도 되지만 설명을 위해서 아래와 같이 함
            value |= (1 << index);
        }
        coin[i] = value;
    }

    go(1);

    cout << answer << '\n';

    return 0;
}