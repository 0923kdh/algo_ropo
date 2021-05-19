#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> adj[20001];
int n, m, a, b, c, startVertex, dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input()
{
    cin >> n >> m;
    cin >> startVertex;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
    }
}

void dijkstra(int startVertex)
{
    fill(dist, dist + 20001, INF);

    dist[startVertex] = 0;
    pq.push({ 0, startVertex });

    while (pq.size())
    {
        int curVertex = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (dist[curVertex] != curDist)
            continue;

        for (auto next : adj[curVertex])
        {
            int nextDist = next.first;
            int nextVertex = next.second;
            if (dist[nextVertex] > dist[curVertex] + nextDist)
            {
                dist[nextVertex] = dist[curVertex] + nextDist;
                pq.push({ dist[nextVertex], nextVertex });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    dijkstra(startVertex);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] >= INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}