#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Horse {
    int y, x, dir;
};

int n, k, y, x, dir, board[14][14], d[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
map<int, Horse> horseInfo; //<horesNum, Horse>
vector<int> horse[14][14]; //horse[y][x] == horseNum

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> y >> x >> dir;
        y--, x--, dir--;
        horse[y][x].push_back(i);
        horseInfo[i] = { y, x, dir };
    }
}

bool isGameFinish() {
    for (int horseNum = 0; horseNum < k; horseNum++) {
        int cy = horseInfo[horseNum].y;
        int cx = horseInfo[horseNum].x;
        int dir = 0, dy = 0, dx = 0, movingHorseStartNum = 0;
        for (int j = 0; j < horse[cy][cx].size(); j++) {
           if (horseNum == horse[cy][cx].at(j)) {
                dir = horseInfo[horseNum].dir;
                dy = d[dir][0];
                dx = d[dir][1];
                movingHorseStartNum = j;
                break;
            }
        }

        int ny = cy + dy;
        int nx = cx + dx;
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 2) {
            if (dir == 0) {
                dir = horseInfo[horseNum].dir = 1;
            }
            else if (dir == 1) {
                dir = horseInfo[horseNum].dir = 0;
            }
            else if (dir == 2) {
                dir = horseInfo[horseNum].dir = 3;
            }
            else {
                dir = horseInfo[horseNum].dir = 2;
            }

            dy = d[dir][0];
            dx = d[dir][1];
            ny = cy + dy;
            nx = cx + dx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 2) {
                continue;
            }
        }

        if (board[ny][nx] == 0) {
            for (int k = movingHorseStartNum; k < horse[cy][cx].size(); k++) {
                int horseNum = horse[cy][cx].at(k);
                horseInfo[horseNum].y = ny;
                horseInfo[horseNum].x = nx;
                horse[ny][nx].push_back(horseNum);
            }
        }

        if (board[ny][nx] == 1) {
            for (int k = horse[cy][cx].size() - 1; k >= movingHorseStartNum; k--) {
                int horseNum = horse[cy][cx].at(k);
                horseInfo[horseNum].y = ny;
                horseInfo[horseNum].x = nx;
                horse[ny][nx].push_back(horseNum);
            }
        }

        int cnt = horse[cy][cx].size() - movingHorseStartNum;
        while (cnt) {
            horse[cy][cx].pop_back();
            cnt--;
        }

        if (horse[ny][nx].size() > 3)
            return true;
    }

    return false;
}

int runCount() {
    int cnt = 1;
    while (cnt < 1000) {
        if (isGameFinish())
            break;
        cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    int cnt = runCount();
    cout << ((cnt < 1000) ? cnt : -1) << "\n";
    return 0;
}