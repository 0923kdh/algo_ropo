#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, lo, hi, cnt, maxLen;
string s;
vector<int> v(26);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    int len = s.size();     

    v[s[0]-'a']++;
    cnt = 1;
    while(lo < len && hi < len) {
        if(cnt <= n)
            maxLen = max(maxLen, hi - lo + 1);

        hi++;
        if(hi == len)
            break;
        
        if(v[s[hi]-'a'] == 0)
            cnt++;
        v[s[hi]-'a']++;

        while(cnt > n && lo < hi) {
            if(v[s[lo]-'a'] == 1)
                cnt--;
            v[s[lo]-'a']--;
            lo++;
        }        
    }
    
    cout << maxLen << "\n";

    return 0;
}