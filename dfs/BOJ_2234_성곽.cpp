#include <bits/stdc++.h>
using namespace std;

int n, m, arr[51][51], visited[51][51], area[51], dy[] = { 0, -1, 0, 1 }, dx[] = { -1, 0, 1, 0 };
int roomCnt, roomSize1, roomSize2;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int go(int y, int x, int num)
{
    visited[y][x] = roomCnt;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        //벽으로 막힌 경우
        if (bitset<4>(arr[y][x]).test(i))
            continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= m || ny < 0 || nx >= n || nx < 0 || visited[ny][nx])
            continue;

        cnt += go(ny, nx, num);
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j])
                continue;

            roomCnt++;
            int roomArea = go(i, j, 1);
            area[roomCnt] = roomArea;
            roomSize1 = max(roomSize1, roomArea);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < m)
            {
                if (visited[i][j] == visited[i + 1][j])
                    continue;

                roomSize2 = max(roomSize2, area[visited[i][j]] + area[visited[i + 1][j]]);
            }

            if (j + 1 < n)
            {
                if (visited[i][j] == visited[i][j + 1])
                    continue;

                roomSize2 = max(roomSize2, area[visited[i][j]] + area[visited[i][j + 1]]);
            }
        }
    }

    cout << roomCnt << '\n';
    cout << roomSize1 << '\n';
    cout << roomSize2 << '\n';

    return 0;
}