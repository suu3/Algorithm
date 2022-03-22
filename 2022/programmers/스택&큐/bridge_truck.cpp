#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int length[10000] = {};
    queue<pair<int, int>> truck_wait;
    deque<pair<int, int>> truck_ing;
    
    for(int i = 0 ; i < truck_weights.size() ; i++){
        truck_wait.push({truck_weights[i], i});
    }
    
    int sec = 0; // answer
    int cur_w = 0; // 다리를 건너는 트럭들의 무게 기록
    while(!truck_wait.empty() || !truck_ing.empty()){
        sec++;
        
        //한칸씩 이동
        if(!truck_ing.empty()){
            
            //맨 앞 pop
            if(length[truck_ing.front().second]==bridge_length){
                cur_w -= truck_ing.front().first;
                truck_ing.pop_front();
            }
            
            // 중간 한칸씩 이동
            int start_index = truck_ing.front().second;
            int end_index = truck_ing.back().second;
            for(int i = start_index ; i <= end_index ; i++ ){
                length[i]++;
            }
                        
        }
        
        //맨 끝 push
        if(!truck_wait.empty()){
            // 견딜 수 있는 무게이다.
            if(truck_wait.front().first + cur_w <= weight){ 
                cur_w += truck_wait.front().first;
                truck_ing.push_back({truck_wait.front().first, truck_wait.front().second});
                length[truck_wait.front().second] = 1;
                truck_wait.pop();
            }
        }

    }
    
    answer = sec;
    return answer;
}