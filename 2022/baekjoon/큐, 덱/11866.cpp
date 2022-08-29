// 11866 요세푸스 문제 0
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    
    int n, k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        q.push(i);
    }
    
    cout << "<";
    while(!q.empty()){
        
        //k-1번 옮김
        for(int i = 0 ; i < k-1 ; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        
        if(q.size()==1){
            cout << q.front();
        }else{
            cout << q.front() << ", ";
        }
        q.pop();
    }
    cout <<">";
    
    return 0;
}