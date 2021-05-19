#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> adj[20001];
int n, m, a, b, c, startVertex, endVertex, dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//시간복잡도
//O(ElogE)
//힙에 들어가는건 거리와 정점의 조합 = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//하나의 정접을 검사할때마다 연결된 모든 간선을 검사하는데 검사할때마다 힙에 뭔가 들어갈 수 있거나 없음.
//최대 간선의 개수만큼 들어갈 수 있기때문에 힙에 들어갈수 있는건 최대 E개라고 볼 수 있고
//간선이 업데이트 될 때 마다 {거리, 정점} 조합이 힙에 들어갔다가 나옴.
//힙은 로그 시간이 걸리기 때문에 최대 ElogE 가 걸린다

//ElogV도 할 수 있다. 힙에 같은 조합을 안넣어줄수있게만하면된다. ->set 추가 사용하면 된다.

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

    cout << dist[endVertex] << '\n';

    return 0;
}