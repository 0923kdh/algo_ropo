#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k, m, v, c, ans;
vector<pair<ll,ll>> jewel;
vector<ll> bag; 
priority_queue<ll> pq; 

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> m >> v;
        jewel.push_back({m, v}); 
	}

	for(int i = 0; i < k; i++) {
        cin >> c;
        bag.push_back(c); 
    }

    sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	
	int j = 0; 
	for(int i = 0; i < k; i++){
		while(j < n && jewel[j].first <= bag[i]) {
            pq.push(jewel[j++].second);
        } 

		if(pq.size()){
			ans += pq.top(); 
            pq.pop();
		}
	} 
    
	cout << ans << "\n";
  
    return 0;
}