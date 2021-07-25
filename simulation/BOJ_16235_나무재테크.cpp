#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, board[101][101], a[101][101], xPos, yPos, age;
int adj[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
vector<vector<int>> tree(101);
vector<pair<int, int>> dieTree;

void init(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            board[i][j] = 5;
        }
    }

    for(int i = 0; i < m; i++){
        cin >> xPos >> yPos >> age;
        xPos--, yPos--;
        int treeNum = (xPos * n)  + yPos;
        tree[treeNum].push_back(age);
    }
}

void spring() {
    dieTree.clear();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            int treeNum = (i * n) + j;
            if(tree[treeNum].size() == 0)
                continue;

            if(tree[treeNum].size() > 1) {
                sort(tree[treeNum].begin(), tree[treeNum].end());
            }
 
            for(int k = 0; k < tree[treeNum].size(); k++){
                //자신의 나이만큼 양분을 먹고 나이가 +1 증가한다.
                int treeAge = tree[treeNum][k];
                int nourishment = board[treeNum / n][treeNum % n];
                bool isSuffice = true;
                if(tree[treeNum][k] <= nourishment && isSuffice) {
                    board[treeNum / n][treeNum % n] -= treeAge;
                    tree[treeNum][k] += 1;
                    if(board[treeNum / n][treeNum % n] == 0) {
                        isSuffice = false;
                    }
                } else {
                    dieTree.push_back({treeNum, tree[treeNum].size() - k});
                    break;
                }
            }
        }
    }
}

void summer() {
    for(int i = 0; i < dieTree.size(); i++) {
        int treeCnt = dieTree[i].second;
        while(treeCnt--) {
            board[dieTree[i].first / n][dieTree[i].first % n] += tree[dieTree[i].first].back() / 2;
            tree[dieTree[i].first].pop_back();
        }
    }
}

void fall() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            int treeNum = (i * n) + j;
            for(int k = 0; k < tree[treeNum].size(); k++){
                if(tree[treeNum][k] % 5 != 0)
                    continue;
                
                for(int l = 0; l < 8; l++){
                    int ny = (treeNum / n) + adj[l][0];
                    int nx = (treeNum % n) + adj[l][1];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) 
                        continue;

                    tree[(ny * n) + nx].push_back(1);
                }
            }
        }
    }
}

void winter() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            board[i][j] += a[i][j];
        }
    }
}

int getAns() {
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            int treeNum = (i * n) + j;
            ans += tree[treeNum].size();
        }
    }
    
    return ans;
}

void run() {
    while(k--) {
        spring();
        summer();
        fall();
        winter();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    run();

    cout <<  getAns();

    return 0;
}