#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int n, board[125][125], dist[125][125], dy[] = { -1, 0, 1, 0}, dx[] = { 0, 1, 0, -1 };
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //weight, y, x

void dijkstra()
{
    pq.push({ board[0][0], {0 , 0}});
    dist[0][0] = board[0][0];

    while(pq.size())
    {
        int curWeigth = pq.top().first;
        int curY = pq.top().second.first;
        int curX = pq.top().second.second;
        pq.pop();

        if(dist[curY][curX] != curWeigth)
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
                continue;

            if(dist[nextY][nextX] > curWeigth + board[nextY][nextX])
            {
                dist[nextY][nextX] = curWeigth + board[nextY][nextX];
                pq.push({dist[nextY][nextX], { nextY, nextX }});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 1;
    while(true)
    {
        cin >> n;
        if(n == 0)
            break;

        fill(&dist[0][0], &dist[0][0]+125 * 125, INF);
        fill(&board[0][0], &board[0][0]+125 * 125, 0);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }

        dijkstra();
        cout << "Problem " << count << ": " << dist[n-1][n-1] << '\n';
        count++;
    }

    return 0;
}