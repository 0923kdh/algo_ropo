#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c, t, ans, board[51][51], temp[51][51], d[4][2] = {{-1 , 0}, {0, 1}, {1, 0}, {0, -1}};
pair<int, int> air;
 
void init() {
    cin >> r >> c >> t;
    bool flag = true;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == -1 && flag) {
                air = {i, i+1};
                flag = false;
            }
        }
    }
}

void go(int row, int col) {
    int regionCnt = 0;
    for(int i = 0; i < 4; i++) {
        int ny = d[i][0] + row;
        int nx = d[i][1] + col;

        if(ny >= r || ny < 0 || nx >= c || nx < 0)
            continue;

        if((ny == air.first || ny == air.second) && nx == 0)
            continue;

        temp[ny][nx] += board[row][col] / 5;
        regionCnt++;       
    }
    temp[row][col] += board[row][col] - ((board[row][col] / 5) * regionCnt);
}

void clear1() {
    queue<int> q;
    for(int i = 1; i < c - 1; i++) {
        q.push(board[air.first][i]);
    }
    for(int i = 1; i <= air.first; i++) {
        q.push(board[i][c-1]);
    }
    for(int i = 1; i < c; i++) {
        q.push(board[0][i]);
    }
    for(int i = 0; i < air.first; i++) {
        q.push(board[i][0]);
    }

    while(q.size()) {
        board[air.first][1] = 0;
        for(int i = 2; i < c; i++) {
            board[air.first][i] = q.front();
            q.pop();
        }
        for(int i = 0; i < air.first; i++) {
            board[i][c-1] = q.front();
            q.pop();
        }
        for(int i = 0; i < c-1; i++) {
            board[0][i] = q.front();
            q.pop();
        }
        for(int i = 1; i < air.first; i++) {
            board[i][0] = q.front();
            q.pop();
        }
        q.pop();
    }   
}

void clear2() {
    queue<int> q;
    for(int i = 1; i < c - 1; i++) {
        q.push(board[air.second][i]);
    }
    for(int i = air.second; i < r - 1; i++) {
        q.push(board[i][c-1]);
    }
    for(int i = 1; i < c; i++) {
        q.push(board[r-1][i]);
    }
    for(int i = air.second + 1; i < r; i++) {
        q.push(board[i][0]);
    }

    while(q.size()) {
        board[air.second][1] = 0;
        for(int i = 2; i < c; i++) {
            board[air.second][i] = q.front();
            q.pop();
        }
        for(int i = air.second + 1; i < r; i++) {
            board[i][c-1] = q.front();
            q.pop();
        }   
        for(int i = 0; i < c-1; i++) {
            board[r-1][i] = q.front();
            q.pop();
        }
        q.pop();
        for(int i = air.second + 1; i < r - 1; i++) {
            board[i][0] = q.front();
            q.pop();
        }
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();

    //미세먼지 확산 양을 칸마다 계산하면 안되고,
    //기존 미세먼지 원본 맵을 한바퀴 다 순회하면서 
    //임시 맵에다가 각 칸이 얼마나 증가되었는지 다 담아야 한다.
    //원본 맵을 전체 순회한 다음에 
    //임시 맵의 값을 원본 맵에 갱신시켜야 한다.
    while(t--){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if((i == air.first || i == air.second) && j == 0)
                    continue;

                if(board[i][j] == 0)
                    continue;

                go(i, j);
            }
        }

        copy(&temp[0][0], &temp[0][0] + 51 * 51, &board[0][0]);
        fill(&temp[0][0], &temp[0][0] + 51 * 51, 0);

        clear1();
        clear2();
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if((i == air.first || i == air.second) && j == 0)
                continue;
            ans += board[i][j];
        }
    }

    cout << ans << "\n";

    return 0;
}