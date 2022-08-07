#include<iostream>
#include<memory.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    int arr[n+1];
    memset(arr, 0, sizeof(arr));

    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    int ans = dp[1];

    for(int i = 1 ; i <= n ; i++){
        if(dp[i] < 0){
            dp[i] = max(dp[i-1] + arr[i], arr[i]);
            ans = max(ans, dp[i]);
        }
    }

    cout << ans;

    return 0;
}