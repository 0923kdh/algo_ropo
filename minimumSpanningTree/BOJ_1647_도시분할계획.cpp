#include<bits/stdc++.h>

using namespace std;

int n, m, answer, parent[100001];
vector<pair<int, pair<int, int>>> edge;

int getParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent[x]);
}

void merge(int x, int y)
{
    x = getParent(x);
    y = getParent(y);

    if (x == y)
        return;

    if (x > y)
        parent[y] = x;
    else
        parent[x] = y;
}

bool isSameParent(int x, int y)
{
    x = getParent(x);
    y = getParent(y);

    return x == y ? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({ c, { a, b } });
    }

    sort(edge.begin(), edge.end());

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int size = 0;
    int index = 0;
    while (size < n - 2)
    {
        if (isSameParent(edge[index].second.first, edge[index].second.second) == false)
        {
            merge(edge[index].second.first, edge[index].second.second);
            answer += edge[index].first;
            size++;
        }
        index++;
    }

    cout << answer << "\n";

    return 0;
}