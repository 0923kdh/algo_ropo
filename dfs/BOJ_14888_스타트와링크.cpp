#include <iostream>

using namespace std;

int n, ans = 987654321, arr[21][21], visit[21];

void init() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

void go(int nextIndex, int cnt) {
    if(cnt == n / 2) {
        int aTeamSum = 0, bTeamSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(visit[i] && visit[j]) {
                    aTeamSum += arr[i][j];
                    aTeamSum += arr[j][i];
                } 
                if(visit[i] == 0 && visit[j] == 0) {
                    bTeamSum += arr[i][j];
                    bTeamSum += arr[j][i];
                }
            }
        }
        ans = min(ans, abs(aTeamSum - bTeamSum));
    }

    for(int i = nextIndex; i < n; i++) {
        visit[i] = 1;
        go(i + 1, cnt + 1);
        visit[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    go(0, 0);
    cout << ans << "\n";
    return 0;
}