#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

struct INFO
{
    int weight, vertex, order;
};

struct compare
{
    bool operator()(const INFO& a, const INFO& b)
    {
        return a.weight > b.weight;
    }
};

int n, m, a, b, weight, result, foxDist[4003], wolfDist[4003][2]; //wolfDist[방문한정점][홀수 or 짝수]
vector<INFO> adj[4003];

void dijkstra1()
{
    priority_queue<INFO, vector<INFO>, compare> pq;
    fill(foxDist, foxDist+4003, INF);
    foxDist[1] = 0;
    pq.push({ 0, 1, 0 });

    while(pq.size())
    {
        int curDist = pq.top().weight;
        int curVertex = pq.top().vertex;
        pq.pop();

        if(foxDist[curVertex] != curDist)
            continue;

        for(const auto& next : adj[curVertex])
        {
            int nextDist = next.weight; 
            int nextVertex = next.vertex;

            if(foxDist[nextVertex] > foxDist[curVertex] + nextDist)
            {
                foxDist[nextVertex] = foxDist[curVertex] + nextDist;
                pq.push({ foxDist[nextVertex], nextVertex, 0 });
            }
        }
    }
}

void dijkstra2()
{
    priority_queue<INFO, vector<INFO>, compare> pq;
    fill(&wolfDist[0][0], &wolfDist[0][0]+4003*2, INF);
    wolfDist[1][0] = 0;
    pq.push({ 0, 1, 0 });

    while(pq.size())
    {
        int curDist = pq.top().weight;
        int curVertex = pq.top().vertex;
        int curOrder = pq.top().order;
        pq.pop();

        if(wolfDist[curVertex][curOrder] != curDist)
            continue;

        for(const auto& next : adj[curVertex])
        {
            int nextDist = next.weight; 
            int nextVertex = next.vertex;

            //curOrder가 짝수일 경우에 nextDist/2, curOrder가 홀수일 경우에 nextDist*2
            nextDist = !curOrder ? (nextDist / 2) : (nextDist * 2);
            if(wolfDist[nextVertex][!curOrder] > wolfDist[curVertex][curOrder] + nextDist)
            {
                wolfDist[nextVertex][!curOrder] = wolfDist[curVertex][curOrder] + nextDist;
                pq.push({ wolfDist[nextVertex][!curOrder], nextVertex, !curOrder });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> weight;
        adj[a].push_back({ weight * 2, b, 0 });
        adj[b].push_back({ weight * 2, a, 0 });
    }

    //여우 가중치
    dijkstra1();

    //늑대 가중치
    //늑대는 정점이 바뀌었을때 /2 를 하거나 *2를 해주어야한다.
    dijkstra2();
    for(int i = 1; i <= n; i++)
    {
        int minDist = min(wolfDist[i][0], wolfDist[i][1]); 
        if(foxDist[i] < minDist)
        {
            result++;
        }
    }

    cout << result << '\n';
    return 0;
}