#include <iostream>
#include <stack>

using namespace std;

int n, num, ans;
stack<pair<int, int>> s; //num, index

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num;

        if(i == 1) {
            s.push({num, i});
            cout << ans << " ";
            continue;
        } 

        if(s.top().first < num) {
            while(s.size()) {
                if(s.top().first > num) {
                    ans = s.top().second;
                    break;
                }                    
                s.pop();
            }
        } else {
            if(s.size()) {
                ans = s.top().second;
            }
        }

        if(s.empty()) {
            ans = 0;
        }
       
        cout << ans << " ";

        s.push({num ,i});
    }
   
    return 0;
}