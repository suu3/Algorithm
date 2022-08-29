// 1966 프린터 큐
#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int arr[n];
        map<int, int> imp; // 자신보다 중요도가 높은 원소 개수 저장
        queue<int> q;
        
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            q.push(i);
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==j) continue;
                
                if(arr[i] < arr[j]) imp[i]++;
            }
        }
        

        int count = 1;
        while(!q.empty()){
            int f = q.front();
            if(!imp[f]){ // f보다 중요도가 높은 원소가 없으면
                if(f == m){
                    cout << count << "\n";
                    break;
                }
                q.pop();

                // 중요도가 높은 애 하나를 pop 했으니 map 갱신
                for(int i = 0 ; i < n ; i++){
                    if(arr[i] < arr[f])
                        imp[i]--;
                }
                count++;
                continue;
            }
            
            
            //뒤에 재배치
            q.pop();
            q.push(f);
        }
        
    }
    return 0;
}