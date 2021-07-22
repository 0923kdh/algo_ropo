#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visit[20001];
vector<int> adj[20001];

void go(int startVertex, int depth) {
    if(visit[startVertex] > depth) {
        visit[startVertex] = depth;
    }
    else if(visit[startVertex] != 0)
        return;
    
    visit[startVertex] = depth;
    for(int i = 0; i < adj[startVertex].size(); i++) {
        go(adj[startVertex][i], depth+1);
    }
}

int solution(int n, vector<vector<int>> edge) {

    for(int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }

    go(1, 1);
  
    return count(visit, visit + n + 1, *max_element(visit, visit + n + 1));
}