#include <iostream>

using namespace std;

int n, a[21], visited[20*100000+2];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
                sum += a[j];
        }
        visited[sum] = 1;
    }

    for(int i = 1; i < 20*100000+3; i++)
    {
        if(visited[i] == 0)
        {
            cout << i << "\n";
            break;
        }
    }

	return 0;
}