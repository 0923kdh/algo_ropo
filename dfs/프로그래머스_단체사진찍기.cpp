#include <bits/stdc++.h>

using namespace std;

int answer, visited[10];
char arr[8] = "";
char str[] = "ACFJMNRT";
vector<string> v;

bool check(string s)
{
    bool isSucceed = true;
    for (int i = 0; i < v.size(); i++)
    {
        int index1 = -1, index2 = -1;
        for (int j = 0; j < 8; j++)
        {
            if (index1 != -1 && index2 != -1)
                break;

            if (s[j] == v[i][0])
                index1 = j;

            if (s[j] == v[i][2])
                index2 = j;
        }

        int interval = abs(index1 - index2) - 1;
        if (v[i][3] == '>')
        {
            if (interval > v[i][4] - '0')
                continue;
        }
        else if (v[i][3] == '<')
        {
            if (interval < v[i][4] - '0')
                continue;
        }
        else
        {
            if (interval == v[i][4] - '0')
                continue;
        }
        isSucceed = false;
    }

    if (isSucceed)
        return true;
    else
        return false;
}

void go(int num)
{
    if (num == 8)
    {
        string temp = "";
        for (int i = 0; i < 8; i++)
        {
            temp += arr[i];
        }

        if (check(temp))
            answer++;

        return;
    }

    for (int i = 1; i <= 8; i++)
    {
        if (visited[i])
            continue;

        visited[i] = 1;
        arr[num] = str[i - 1];
        go(num + 1);
        visited[i] = 0;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    answer = 0;
    v = move(data);
    go(0);

    return answer;
}