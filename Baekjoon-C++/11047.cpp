#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (int a, int b){
    return a > b;
}

int main() {
    int N, K;
    vector<int> arr;
    cin >> N >> K;
    arr.assign(10, 0);
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);

    int count = 0;
    for(int i = 0 ; i < N ; i++){
        while(true){
            if( K - arr[i] < 0) break;
            K-= arr[i];
            count++;
        }
//        cout << K << " ";
    }
    cout << count;


    return 0;
}