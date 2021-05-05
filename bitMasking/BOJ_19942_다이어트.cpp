#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n, mp, mf, ms, mv, a, b, c, d, sum, answer = INF;
map<int, vector<vector<int>>> m;

struct FoodInfo
{
    int mp, mf, ms, mv, cost;
};
FoodInfo foodInfo[16];

void input()
{
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
    {
        cin >> foodInfo[i].mp >> foodInfo[i].mf >> foodInfo[i].ms >> foodInfo[i].mv >> foodInfo[i].cost;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();

    // (1 << n) == 2^n
    for (int i = 1; i < (1 << n); i++)
    {
        a = 0, b = 0, c = d = sum = 0;
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                v.push_back(j + 1);
                a += foodInfo[j].mp;
                b += foodInfo[j].mf;
                c += foodInfo[j].ms;
                d += foodInfo[j].mv;
                sum += foodInfo[j].cost;
            }
        }

        if (a >= mp && b >= mf && c >= ms && d >= mv)
        {
            if (answer >= sum)
            {
                answer = sum;
                m[answer].push_back(v);
            }
        }
    }

    if (answer == INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        sort(m[answer].begin(), m[answer].end());
        cout << answer << '\n';
        for (int a : m[answer][0])
        {
            cout << a << " ";
        }
    }

    return 0;
}