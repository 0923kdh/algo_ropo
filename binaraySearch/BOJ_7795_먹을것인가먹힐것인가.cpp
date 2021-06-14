#include<bits/stdc++.h>

using namespace std;

int t, n, m, num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    vector<int> ansList;
    while (t--)
    {
        cin >> n >> m;
     
        vector<int> aList, bList;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            aList.push_back(num);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> num;
            bList.push_back(num);
        }

        sort(bList.begin(), bList.end());

        int count = 0;
        for (const auto& a : aList)
        {
            count += lower_bound(bList.begin(), bList.end(), a) - bList.begin();
        }
        ansList.push_back(count);
    }

    for (const auto& ans : ansList)
    {
        cout << ans << "\n";
    }
 
    return 0;
}