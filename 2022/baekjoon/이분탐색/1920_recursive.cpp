// 1920 수 찾기 (재귀 ver)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void binary_search(int t, int l, int r){
    if(l > r){
        cout << "0\n";
        return;
    }
    
    int mid = (l + r) / 2;
    if(arr[mid] > t){
        binary_search(t, l, mid - 1);
    }else if(arr[mid] < t){
        binary_search(t, mid + 1, r);
    }else{
        cout << "1\n";
        return;
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
        binary_search(target, 0, N-1);
    }
    

    return 0;
}