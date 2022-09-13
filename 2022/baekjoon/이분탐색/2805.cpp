#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 2805 나무 자르기 (parametric search)
 *  
 */


long long ans = 0;

void binary_search(long long *arr, int n, int m){
    long long l = 1;
    long long r = arr[n-1];
    
    while(true){
        if(l > r){
            return;
        }
        
        long long H = (l + r) / 2; 

        long long count = 0;
        for(int i = 0 ; i < n ; i++){
            long long temp = (arr[i] - H);
            if(temp > 0){
                count += temp;
            }
        }
        if (count < m){
            r = H - 1;
        }else{
            ans = max(ans, H);
            l = H + 1;
        }
    }
    
}


int main() {
    int n, m;
    cin >> n >> m;
    long long arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    binary_search(arr, n, m);
    
    cout << ans;


	return 0;
}