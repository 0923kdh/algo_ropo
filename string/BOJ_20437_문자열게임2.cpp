#include <bits/stdc++.h>

using namespace std;

int t, num;
string w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> w >> num;

        vector<int> v[26];
        for (int i = 0; i < w.size(); i++) {
            v[w[i]-'a'].push_back(i);
        }

        int minValue = 987654321, maxValue = -987654321;
        for (int i = 0; i < 26; i++) {
            if(v[i].size() < num)
                continue;

            for (int j = 0; j <= v[i].size() - num; j++) {
                minValue = min(v[i][j+num-1] - v[i][j], minValue);
                maxValue = max(v[i][j+num-1] - v[i][j], maxValue);
            }
        }

        if(minValue == 987654321 && maxValue == -987654321) {
            cout << "-1" << "\n";
        } else {
            cout << minValue + 1 << " " << maxValue + 1 << "\n";
        }
    }

    return 0;
}
