#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k, num;
    cin >> k;
    stack<int> st;
    while(k--){
        cin >> num;
        if(num != 0){
            st.push(num);
        }else{
            st.pop();            
        }
    }
    
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    
    cout << sum;
    return 0;
}