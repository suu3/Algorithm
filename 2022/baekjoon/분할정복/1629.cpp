#include <iostream>
#include <cmath>

using namespace std;

/*
* 1629 곱셈
*
*/

long long func(long long a, long long b, long long c){
    if(b == 1){
        return a % c;
    }
    
    long long temp = func(a, b / 2 , c) % c;
    temp = temp * temp % c;
    if(b % 2){ // 홀수일 때
        return a * temp % c;
    }else{ // 짝수일 때
        return temp % c;
    }
    
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b, c;
    cin >> a >> b >> c ;
    cout << func(a, b, c) % c;
   

    return 0;
}
