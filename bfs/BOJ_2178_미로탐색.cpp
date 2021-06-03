#include <bits/stdc++.h>

using namespace std;

struct INFO
{  
    int y, x, cnt;
};

int n, m, arr[100][100], visited[100][100], dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
string str;

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
}

void go()
{
    queue<INFO> q;
    q.push({0, 0, 1});
    visited[0][0] = 1;

    while(q.size())
    {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(y == n -1 && x == m - 1)
        {
            cout << cnt;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || arr[ny][nx] == 0)
                continue;

            q.push({ny, nx, cnt + 1});
            visited[ny][nx] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);                                                                                                                                                                 
    
    input();
    go();
    
    return 0;
}