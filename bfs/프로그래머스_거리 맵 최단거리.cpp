#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct Info
{
    int y;
    int x;
    int dis;
};
Info info;

int dy[] = { -1, 0 , 1, 0 }, dx[] = { 0, 1, 0, -1 }, visited[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    queue<Info> q;
    q.push({ 0,0,1 });
    visited[0][0] = 1;

    while (q.size())
    {
        int y = q.front().y;
        int x = q.front().x;
        int dis = q.front().dis;
        q.pop();

        if (y == n - 1 && x == m - 1)
        {
            answer = dis;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (maps[ny][nx] == 0 || visited[ny][nx])
                continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx, dis + 1 });
        }
    }

    return answer == 0 ? -1 : answer;
}