#include <bits/stdc++.h>

using namespace std;

int n, m, w, r1, c1, r2, c2, c, tree[1025][1025], arr[1025][1025];

int sum(int row, int col)
{
    int result = 0;
    for(int r = row; r > 0; r -= (r & -r))
    {
        for(int c = col; c > 0; c -= (c & -c))
        {
            result += tree[r][c];
        }
    }
    return result;
}

void update(int row, int col, int num)
{
    for(int r = row; r <= n; r += (r & -r))
    {
        for(int c = col; c <= n; c += (c & -c))
        {
            tree[r][c] += num;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int r = 1; r <= n; r++)
    {
        for(int c = 1; c <= n; c++)
        {
            cin >> arr[r][c];
            update(r, c, arr[r][c]);
        }
    }

    while(m--)
    {
        cin >> w;
        if(w == 0)
        {
            cin >> r1 >> c1 >> c;
            update(r1, c1, c -arr[r1][c1]);
            arr[r1][c1] = c;
        }
        else
        {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sum(r2, c2) - sum(r2, c1-1) - sum(r1-1, c2) + sum(r1-1, c1-1) << "\n";
        }
    }
    return 0;
}