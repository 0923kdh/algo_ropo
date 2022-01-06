#include <bits/stdc++.h>

using namespace std;

int cnt, visited[500001];
vector<int> adj[500001];

void go(int vertex){
    bool isLeafNode = true;
    for(int i = 0; i < adj[vertex].size(); i++) {
        int nextVertex = adj[vertex][i];
        if (visited[nextVertex])
            continue;

        visited[nextVertex] = 1;
        isLeafNode = false;
        go(nextVertex);
    }

    if(isLeafNode)
        cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(11);

    int n, u, v;
    double w;
    cin >> n >> w;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = 1;
    go(1);
    cout << w / cnt;
    return 0;
}
