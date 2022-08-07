#include<iostream>
#include<memory.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[1000001];
    memset(dp, -1, sizeof(dp));

    dp[1] = 1; //1
    dp[2] = 2; //00 11

    for(int i = 1 ; i <= n ; i++){
        if(dp[i] < 0)
            dp[i] = (dp[i-2] + dp[i-1]) % 15746 ; // 00, 11, 1
    }

    cout << dp[n] % 15746 ;

    return 0;
}