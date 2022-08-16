#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];
    int sum[n-k+1] = { 0 };
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < k ; i++){
        sum[0] += arr[i];
    }

    int ans = sum[0];

    for(int i = 1 ; i < n-k+1 ; i++){
        sum[i] = sum[i-1] + arr[i+k-1] - arr[i-1];
        ans = max(ans, sum[i]);
    }

    cout << ans;

    return 0;
}