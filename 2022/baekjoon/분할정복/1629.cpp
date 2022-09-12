#include <iostream>
#include <cmath>

using namespace std;

/*
* 1629 곱셈
* pow 함수를 직접 구현해야하는 문제 (pow를 쓰면 시간초과)
* 나머지를 남발하여 크기를 맞춘다...
*
*
* A(x*y) = (Ax)y
* ex) A^4 = (A^2)^2 (짝수일때)
*     A^5 = A * A^4 = A * (A^2)^2 (홀수일때)
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
