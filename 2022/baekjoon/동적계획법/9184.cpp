#include <iostream>

using namespace std;

int w[21][21][21];

int dp(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;

    if(a > 20 || b > 20 || c > 20) return dp(20, 20, 20);

    if(w[a][b][c] != 0){
        return w[a][b][c];
    }

    if(a < b && b< c){
        w[a][b][c] = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c);
        return w[a][b][c];
    }

    w[a][b][c] = dp(a - 1, b, c) + dp(a - 1, b-1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b- 1, c - 1);
    return w[a][b][c];
}

int main(){
    int a, b, c;
    while(true){
        cin >> a >> b >> c ;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << endl;
    }

    return 0;
}