#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> adj[1001];
int n, m, a, b, c, startVertex, endVertex, dist[1001], from[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
    }

    cin >> startVertex >> endVertex;
}

void dijkstra(int startVertex)
{
    fill(dist, dist + 1001, INF);

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
                from[nextVertex] = curVertex;
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

    cout << dist[endVertex] << '\n';

    vector<int> route;
    while (endVertex)
    {
        route.push_back(endVertex);
        endVertex = from[endVertex];
    }

    cout << route.size() << '\n';

    for (int i = route.size() - 1; i >= 0; i--)
    {
        cout << route[i] << " ";
    }

    return 0;
}