#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, c, startVer, endVer, ans, visited[10001];
vector<pair<int, int>> v[10001];

void input()
{
    cin >> n >> m;
    while(m--)
    {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> startVer >> endVer;
}

bool go(int vertex, int mid)
{
    if(visited[vertex])
        return false;
    
    if(vertex == endVer)
        return true;
    
    visited[vertex] = 1;
    for(const auto& pos : v[vertex])
    {
        int next = pos.first;
        int cost = pos.second;
        if(cost >= mid)
        {
            if(go(next, mid))
                return true;
        }
    }

    return false;
}

void binararySearch()
{   
    int lo = 1, hi = 1000000000;
    while(lo <= hi)
    {
        fill(visited, visited+10001, 0);
        int mid = (lo + hi) / 2;
        if(go(startVer, mid))
        {
            //다리가 갖는 최소 중량 Mid 값을 늘려야 한다는 말이다. (최대값에 도달하지 못했기때문)
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            //다리가 갖는 최소 중량 Mid값을 줄여야 한다는 말이다.(최대값을 넘어섰기때문)
            hi = mid - 1;
        }
    }
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    binararySearch();
    cout << ans << "\n";
	return 0;
}