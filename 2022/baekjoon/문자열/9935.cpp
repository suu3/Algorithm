// 9935 문자열 폭발
// 문자열을 스택에 넣어가며 타겟 문자열과 맨 오른쪽 글자에서부터 비교한다.
// 타겟과 일치하지 않으면 스택에 다시 복구시켜준다.

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, target;
    cin >> str >> target;
    stack<char> st;
     
    for(int i = 0 ; i < str.length() ; i++){
        char cur = str[i];
        st.push(cur);
        if(cur == target[target.length() - 1]){
            int start = target.length() - 1;
            int end = start;
            while(!st.empty() && end > 0){
                if(st.top() == target[end]){
                    st.pop();
                    end--;
                }else{
                    break;
                }
            }
            if(!st.empty()){
                if(st.top() == target[end] ){
                    st.pop();
                    end--;
                }
            }
            if(end >= 0){ // 다시 넣는 작업
                for(int j = end+1 ; j <= start ; j++){
                    st.push(target[j]);
                }          
            }
            
        }
    }
    
    if(st.empty()){
        cout << "FRULA";
    }else{
        char ans[st.size()];
        int index = 0;
        while(!st.empty()){
            ans[index] = st.top();
            st.pop();
            index++;
        }
        for(int i = sizeof(ans) - 1 ; i >=0  ; i--){
            cout << ans[i];
        }
    }

    return 0;
}