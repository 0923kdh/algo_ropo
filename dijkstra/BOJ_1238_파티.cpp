#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n, m, x, startV, endV, weight, dist[1001], answer[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void input()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> startV >> endV >> weight;
        adj[startV].push_back({ weight, endV });
    }
}

void dijkstra(int startVertex)
{
    fill(dist, dist + 1001, INF);
    dist[startVertex] = 0;

    pq.push({ 0, startVertex });
    while (pq.size())
    {
        int curDist = pq.top().first;
        int curVertex = pq.top().second;
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

    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;

        dijkstra(i);
        answer[i] = dist[x];
    }

    dijkstra(x);
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;

        answer[i] += dist[i];
    }

    cout << *max_element(answer, answer + n + 1);

    return 0;
}