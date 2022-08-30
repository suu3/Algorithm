// 1021 회전하는 큐
#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    deque<int> dq;
    
    cin >> n >> m;
    int arr[m];
    for(int i = 0 ; i < m ; i++){
        cin >> arr[i];
    }

    
    for(int i = 1 ; i <= n ; i++){
        dq.push_back(i);
    }

    int count = 0;
    
    for(int i = 0 ; i < m ; i++){
        int cur = arr[i];

        //find index
        int index = -1;
        for(int j = 0 ; j < dq.size() ; j++){
            if(dq[j] == cur){
                index = j + 1;
            }
        }
        
        if(index - 1 <= dq.size() - (index - 1)){ 
            int cnt = index - 1;
            for(int j = 0 ; j < cnt ; j++){
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
            
        }else if(index - 1 > dq.size() - (index - 1)){
            int cnt = dq.size() - (index - 1);
            for(int j = 0 ; j < cnt ; j++){
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }
        dq.pop_front();
   }
    
    cout << count;
    return 0;
}