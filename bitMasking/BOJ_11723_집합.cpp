#include <bits/stdc++.h>

using namespace std;

int m, n, num;
char str[15];

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s %d", &str, &num);
        if (str[0] == 'a' && str[1] == 'd') n |= (1 << num);
        else if (str[0] == 'r') n &= ~(1 << num);
        else if (str[0] == 'c') cout << ((n & (1 << num)) == 0 ? 0 : 1) << '\n';
        else if (str[0] == 't') n ^= (1 << num);
        else if (str[0] == 'a' && str[1] == 'l') n = (1 << 21) - 1;
        else n = 0;
    }

    return 0;
}