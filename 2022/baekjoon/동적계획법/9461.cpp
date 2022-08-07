#include<iostream>
#include<memory.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    long long dp[101];
    memset(dp, -1, sizeof(dp));

    while(T--){
        int N;
        cin >> N;


        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        dp[6] = 3;
        for(int i = 1 ; i <= N ; i++){
            if(dp[i] < 0)
                dp[i] = dp[i-1] + dp[i-5];
        }

        cout << dp[N] << endl;
    }
    return 0;
}