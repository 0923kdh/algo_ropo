#include <iostream>
#include <queue>

using namespace std;

int n, m, x, y, ans, dist[101], nextPos[101];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= 100; i++)
    {
        nextPos[i] = i;
        dist[i] = 0;
    }

    while(n--)
    {
        cin >> x >> y;
        nextPos[x] = y;
    }

    while(m--)
    {
        cin >> x >> y;
        nextPos[x] = y;
    }

    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while(q.size())
    {
        int x = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++)
        {
            int nx = x + i;
            if(nx > 100)
                continue;

            nx = nextPos[nx];
            if(dist[nx])
                continue;
            
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }

    cout << dist[100] << "\n";
	return 0;
}