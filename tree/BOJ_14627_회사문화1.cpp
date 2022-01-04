#include <iostream>
#include <vector>

using namespace std;

int n, m, elder, compliment[100001], people, w;
vector<int> adj[100001];

void go(int startVertex, int amount){
    for(auto next : adj[startVertex]){
        compliment[next] += amount;
        go(next, compliment[next]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> elder;
        adj[elder].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        cin >> people >> w;
        compliment[people] += w;
    }

    go(1, compliment[1]);

    for(int i=1; i <= n; i++){
        cout << compliment[i] << " " ;
    }

    return 0;
}
