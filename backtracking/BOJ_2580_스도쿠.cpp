#include <iostream>

using namespace std;

int n = 9, a[10][10], rowcheck[10][10], colCheck[10][10], squareCheck[10][10];

int square(int y, int x)
{
    return (y/3) * 3 + (x/3);
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

bool go(int num)
{
    if(num == 81)
    {
        print();
        return true;
    }

    int y = num / n;
    int x = num % n;
    if(a[y][x])
        return go(num + 1);
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            if(rowcheck[y][i] == 0 && colCheck[x][i] == 0 && squareCheck[square(y,x)][i] == 0)
            {                    
                rowcheck[y][i] = colCheck[x][i] = squareCheck[square(y,x)][i] = 1;
                a[y][x] = i;
                if(go(num + 1))
                    return true;
                rowcheck[y][i] = colCheck[x][i] = squareCheck[square(y,x)][i] = 0;
                a[y][x] = 0;
            }
        }
    }
    return false;
}

void input()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0)
                continue;
            
            rowcheck[i][a[i][j]] = 1;
            colCheck[j][a[i][j]] = 1;
            squareCheck[square(i, j)][a[i][j]] = 1;
        }
    }
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    input();
    go(0);

	return 0;
}