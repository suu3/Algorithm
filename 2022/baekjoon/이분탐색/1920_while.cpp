// 1920 수 찾기 (반복문 ver)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void binary_search(int t, int n){
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    
    while(1){
        if(l > r){
            cout << "0\n";
            return;
        }
            
        int mid = (l + r) / 2;
        if(arr[mid] > t){
            r = mid - 1;
        }else if(arr[mid] < t){
            l = mid + 1;
        }else{
            cout << "1\n";
            return;
        }      
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    arr.assign(N, 0);
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    cin >> M;
  
    for(int i = 0 ; i < M ; i++){
        int target;
        cin >> target;
        binary_search(target, N);
    }
    

    return 0;
}