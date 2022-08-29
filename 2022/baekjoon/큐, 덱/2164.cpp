// 2164 카드 2
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        q.push(i);
    }
    
    while(!q.empty()){
        if(q.size() == 1){
            cout << q.front();
            break;
        }
        
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
        
    }
    
    return 0;
}