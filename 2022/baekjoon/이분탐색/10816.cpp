#include <iostream>

/**
 * 10816 숫자카드 2
 * 이분탐색을 쓰지 않은 코드
 * 
*/

using namespace std;

int arr[500001];
int card[500001];
int ans[20000002] = {0};
int n, m;

#define STANDARD 10000000

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[STANDARD + arr[i]]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card[i];
	}
    
    for(int i = 0 ; i < m ; i++){
        cout << ans[STANDARD + card[i]] << " ";
    }
	return 0;
}