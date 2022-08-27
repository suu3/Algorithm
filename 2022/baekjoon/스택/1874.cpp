// 1874 스택 수열
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    
    stack<int> st;
    cin >> n;
    
    int seq[n];
    int temp[n];
    

    for(int i = 0 ; i < n ; i++){
        cin >> seq[i];
        temp[i] = seq[i];
    }
    
    sort(temp, temp + n);
    
    int length = 0; // pop 한 횟수가 수열 길이와 같아지면 끝이 난다.
    int index = 0;
    string ans = "";
    while(length != n){
        int cur = temp[index];
        st.push(cur);
        ans += "+\n";
        
        while(1){
            if(st.empty() || length==n) break;
            else if (st.top() != seq[length]) break;

            st.pop();
            ans += "-\n";
            length++;

        }
        
        index++;
        if(index == n){
            if(st.size()){
                ans = "NO";
            }
            cout << ans;
            break;
        }
    }
    
    return 0;
}