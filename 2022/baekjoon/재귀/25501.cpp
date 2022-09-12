// 25501 재귀의 귀재
#include <iostream>
#include <string.h>

using namespace std;

int count = 0;
int recursion(const string &s, int l, int r){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const string &s){
    return recursion(s, 0, s.length() - 1);
}

int main(){
    int T;
    string S;
    cin >> T;
    while(T--){
        cin >> S;
        cout << isPalindrome(S) << " " << count << "\n";
        count = 0;
    }

    return 0;
}