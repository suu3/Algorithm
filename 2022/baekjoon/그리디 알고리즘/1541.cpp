// 1541 잃어버린 괄호
// 그리디 알고리즘 - "-" 뒤에를 전부 뺄셈 처리할 때가 최선의 방법.
// 괄호는 여러번 쓸수있다.
#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;
    
    
    string cur = "";
    int sum = 0;
    bool check_minus = false;
    for(int i = 0 ; i <= input.length() ; i++){
        if(input[i] == '-' || input[i] == '+' || i== input.length()){
            if(!check_minus){
                sum += stoi(cur);
            }else{
                sum -= stoi(cur);
            }
            cur = "";
        }else{ // 숫자
            cur += input[i];
        }
        
        if(input[i] == '-') check_minus = true;
    }
    
    cout << sum;

    return 0;
}