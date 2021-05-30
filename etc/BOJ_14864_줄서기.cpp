#include <bits/stdc++.h>

using namespace std;

int n, m, a[100001], exist[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        a[i] = i;

    while(m--)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        a[u]++;
        a[v]--;
    }

    bool isExist = false;
    for(int i = 1; i <= n; i++)
    {
        if(exist[a[i]])
        {
           isExist = true;
           break;
        }
        exist[a[i]] = 1;
    }
    
    if(isExist)
    {
        cout << -1 << '\n';
    }
    else
    {
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }

    return 0;
}