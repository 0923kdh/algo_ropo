#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;
int n, m, temp, answer = INF, arr[11], visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int mask)
{
    visited[here] = 1;
    pair<int, int> tempAnswer = { 1, arr[here] };
    for (int there : adj[here])
    {
        if ((mask & (1 << (there - 1))) == 0)
            continue;

        if (visited[there])
            continue;

        pair<int, int> temp = dfs(there, mask);
        tempAnswer.first += temp.first;
        tempAnswer.second += temp.second;
    }
    return tempAnswer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            adj[i].push_back(temp);
            adj[temp].push_back(i);
        }
    }

    int negativeMask = (1 << n) - 1;
    for (int i = 1; i < (1 << n) - 1; i++)
    {
        fill(visited, visited + 11, 0);

        int aIndex = -1, bIndex = -1;
        for (int j = 0; j < n; j++)
        {
            if (aIndex != -1 && bIndex != -1)
                break;

            if (i & (1 << j))
                aIndex = j + 1;
            else
                bIndex = j + 1;
        }

        pair<int, int> comp1 = dfs(aIndex, i);
        pair<int, int> comp2 = dfs(bIndex, i ^ negativeMask);

        if (comp1.first + comp2.first == n)
            answer = min(answer, abs(comp1.second - comp2.second));
    }

    cout << (answer == INF ? -1 : answer) << '\n';
    return 0;
}