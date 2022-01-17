#include <bits/stdc++.h>

using namespace std;

int n, k;

bool check(int mid){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += min(mid / i, n);
    }

    return cnt < k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    int ans = 0, low = 0, high = k;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid)){
            low = mid + 1;
        }else{
            high = mid - 1;
            ans = mid;
        }
    }

    cout << ans;

    return 0;
}