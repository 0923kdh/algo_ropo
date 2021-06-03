#include <bits/stdc++.h>

using namespace std;

int n, cnt, arr[27][27], visited[27][27], dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
string str;
vector<int> v;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        for(int j = 0; j < str.size(); j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
}

int go(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y,x});
    visited[y][x] = 1;
    int cnt = 1;

    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || arr[ny][nx] == 0)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = 1;
            cnt += 1;
        }
    }

    return cnt;
}

void solved()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] || arr[i][j] == 0)
                continue;

            v.push_back(go(i, j));
            cnt++;
        }
    }
}

void print()
{
    cout << cnt << "\n";
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout<< v[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);                                                                                                                                                                 

    input();
    solved();
    print();

    return 0;
}