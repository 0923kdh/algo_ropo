#include <iostream>
#include <queue>
#include <set>

using namespace std;

string s;
int n, m, a[1000][1000], visited[1000][1000], board[1000][1000];
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
vector<int> groupSize;

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            a[i][j] = s[j] -'0';
        }
    }
}

void go(int y, int x, int cnt)
{
    queue<pair<int, int>> q;
    q.push({y,x});
    visited[y][x] = 1;
    board[y][x] = cnt;
    int tempGroupSize = 1;
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] || visited[ny][nx])
                continue;
            
            q.push({ny,nx});
            visited[ny][nx] = 1;
            board[ny][nx] = cnt;
            tempGroupSize++;
        }
    }
    groupSize.push_back(tempGroupSize);
}

void check()
{
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] || visited[i][j])
                continue;

            go(i,j, cnt);
            cnt++;
        }
    }
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 0)
                cout << 0;
            else
            {
                set<int> near;
                for(int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 0)
                        continue;

                    near.insert(board[ny][nx]);
                }
                int ans = 1;
                for(int num : near)
                {
                    ans += groupSize[num-1];
                }
                cout << ans % 10;
            }
        }
        cout << "\n";
    }
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    check();
    print();
   
	return 0;
}