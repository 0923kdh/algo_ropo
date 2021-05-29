#include <bits/stdc++.h>
 
using namespace std;

const int INF = 987654321;

int tc, n, m, t, s, g, h, a, b, c, x1, distS[2003], distG[2003], distH[2003];
vector<pair<int, int>> adj[2003];
vector<int> destination;

void init()
{
    for(int i = 0; i < 2003; i++)
    {
        adj[i].clear();
    }

    fill(distS, distS+2003, INF);
    fill(distG, distG+2003, INF);
    fill(distH, distH+2003, INF);
    destination.clear();
}

void input()
{
    //교차로 = vertex, 도로 = edge , 목적지 후보의 개수
    cin >> n >> m >> t;
    //출발지, g, h
    cin >> s >> g >> h;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    for(int i = 0; i < t; i++)
    {
        //목적지 후보
        cin >> x1;
        destination.push_back(x1);
    }
}

void dijkstra(int start, int *dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(pq.size())
    {
        int curDist = pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj[curVertex].size(); i++)
        {
            int nextDist = adj[curVertex][i].first;
            int nextVertex = adj[curVertex][i].second;

            if(dist[nextVertex] > curDist + nextDist)
            {
                dist[nextVertex] = curDist + nextDist;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
}

void findDestination()
{
    sort(destination.begin(), destination.end());
    for(int i = 0; i < destination.size(); i++)
    {
        int dest = destination[i];
        //G->H 방향으로 지나는 경우
        if(distS[dest] == distS[g] + distG[h] + distH[dest])
            cout << dest << " ";
        //H->G 방향으로 지나는 경우
        else if(distS[dest] == distS[h] + distH[g] + distG[dest])
            cout << dest << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--)
    {
        init();
        input();
        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);
        findDestination();
    }

    return 0;
}