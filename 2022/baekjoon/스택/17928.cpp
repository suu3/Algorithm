//17928 오큰수
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int input;
    
    stack<int> st;
    
    cin >> n;
    int arr[n];
    int ans[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = n-1 ; i >=0 ; i--){
        int cur = arr[i];
        //cout << "cur " << cur << endl;
        if(st.empty()){
            ans[i] = -1;
            st.push(cur);
            continue;
        }
        
        if(cur < st.top()){
            ans[i] = st.top();
        }else{ //스택 위가 나보다 작으면
            while(st.top() <= cur){
                st.pop();
                
                if(st.empty()) break;
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();  
            }
        }
        st.push(cur);

    }
    
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
   return 0;
}