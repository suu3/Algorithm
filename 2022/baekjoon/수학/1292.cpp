//1292 쉽게 푸는 문제
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int A, B;
    cin >> A >> B;
    vector<int> arr;
    arr.assign(B+1, 0);

    int sum = 0;
    int num = 1;
    int count = 0;
    bool check = false;
    while(true){
        for(int j = 0 ; j < num ; j++){
            count++;
            sum += num;
            if(count==B){
                check = true;
                break;
            }
        }
        num++;
        if(check)
            break;
    }

    num = 1;
    count = 0;
    check = false;

    if(A!=1){
        while(true){
            for(int j = 0 ; j < num ; j++){
                count++;
                sum -= num;
                if(count==A-1){
                    check = true;
                    break;
                }
            }
            num++;
            if(check)
                break;
        }

    }

    cout << sum;
    return 0;
}