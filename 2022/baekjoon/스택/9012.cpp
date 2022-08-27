//9012 스택
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    string str;
    while(T--){
        stack<char> st; // 테스트 케이스마다 스택 새로 생성
        cin >> str;
        for(int i = 0 ; i < str.length() ; i++){
            char ps = str[i];
            // '('가 나오면 스택에 넣고, ')'이 나오면 스택 원소를 하나 제거해서 짝을 맞춘다.
            if(ps == '('){
                st.push(ps);
            }else{ // )
                if(st.empty()){ //스택이 비었는데 ')'가 나옴 : 짝이 안 맞는다.
                    cout << "NO\n";
                    break;
                }
                st.pop();
            }
            
            // 모든 문자 검사가 끝남
            if(i == str.length() - 1){
              if(!st.empty()){ //다 끝났는데 스택에 비지 않았음 : 짝이 안 맞는다.
                    cout << "NO\n";
                }else{
                    cout << "YES\n";
                }
                
            }
        }
        
    }
    
    return 0;
}