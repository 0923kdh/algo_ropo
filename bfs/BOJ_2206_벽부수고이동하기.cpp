#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

string s;
int n, m, a[1000][1000], visited[1000][1000][2], dy[] = { -1, 0 , 1, 0 }, dx[] = { 0, 1, 0, -1 };

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
}

void go()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0 ,0});
    visited[0][0][0] = 1;

    while(q.size())
    {
        int y, x, z;
        tie(y ,x, z) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if(a[ny][nx] == 0 && visited[ny][nx][z] == 0)
            {
                visited[ny][nx][z] = visited[y][x][z] + 1;
                q.push({ny, nx, z});
            }

            if(z == 0 && a[ny][nx] == 1 && visited[ny][nx][z+1] == 0)
            {
                visited[ny][nx][z+1] = visited[y][x][z] + 1;
                q.push({ny, nx, z+1});
            }
        }
    }
}

void print()
{
    if(visited[n-1][m-1][0] != 0 && visited[n-1][m-1][1] != 0)
        cout << min(visited[n-1][m-1][0], visited[n-1][m-1][1]);
    else if(visited[n-1][m-1][0] != 0)
        cout << visited[n-1][m-1][0];
    else if(visited[n-1][m-1][1] != 0)
        cout << visited[n-1][m-1][1];
    else
        cout << -1;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    input();
    go();
    print();

	return 0;
}