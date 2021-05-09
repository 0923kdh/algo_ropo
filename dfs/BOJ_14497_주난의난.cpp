#include<bits/stdc++.h>

using namespace std;

int m, n, isVisited[301][301], jump, posX1, posX2, posY1, posY2;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool flag = false;
char arr[301][301];

void dfs(int y, int x)
{
    isVisited[y][x] = 1;
    if (y == posY2 - 1 && x == posX2 - 1)
    {
        flag = true;
        return;
    }

    if (arr[y][x] == '1')
    {
        arr[y][x] = 0;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || isVisited[ny][nx])
            continue;

        dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> posY1 >> posX1;
    cin >> posY2 >> posX2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> arr[i][j];
        }
    }

    while (1)
    {
        fill(&isVisited[0][0], &isVisited[0][0] + 301 * 301, 0);

        dfs(posY1 - 1, posX1 - 1);
        jump++;
        if (flag)
            break;
    }

    cout << jump << "\n";

    return 0;
}