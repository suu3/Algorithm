#include <iostream>
#include <algorithm>

/**
 *  1654 랜선 자르기 (parametric search)
 * 주의점
 * 1. N개보다 많은 것도 N개를 만드는 것에 포함된다.
 * 2. 랜선의 길이는 2^31-1 이하이다.
 * 
 */


using namespace std;

long long ans = 0;

void binary_search(long long *arr, int k, int n){
    long long l = 1;
    long long r = arr[k-1];
    
    while(true){
        if(l > r){
            return;
        }
        
        long long mid = (l + r) / 2; // 길이
     
        int count = 0;
        for(int i = 0 ; i < k ; i++){
            count += (arr[i] / mid);
        }

        if (count < n){ // 길이를 줄인다
            r = mid - 1;
        }else{ //길이를 늘린다 ( N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다.)
            ans = max(ans, mid);
            l = mid + 1;
        }
    }
    
}


int main() {
    int k, n;
    cin >> k >> n;
    long long arr[k];
    for(int i = 0 ; i < k ; i++){
        cin >> arr[i];
    }
    sort(arr, arr + k);
    binary_search(arr, k, n);
    cout << ans;
	return 0;
}