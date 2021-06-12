#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int ret = INF, n, a[11][11], visited[11][11];

bool check(int y, int x)
{
    if (visited[y][x])
        return false;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
            return false;

    }
    return true;
}

int flowerCheck(int y, int x)
{
    int sum = a[y][x];
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        sum += a[ny][nx];
        visited[ny][nx] = 1;
    }
    return sum;
}

void flowerRollback(int y, int x)
{
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void go(int sum, int flower)
{
    if (flower == 0)
    {
        ret = min(ret, sum);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i, j))
            {
                int flowerSum = flowerCheck(i, j);
                go(sum + flowerSum, flower - 1);
                flowerRollback(i, j);
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 3);

    cout << ret << "\n";

    return 0;
}