#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> list;
    int lo[100] = {};
    int index[100] = {};
        
    for(int i = 0 ; i < priorities.size() ; i++){
        for(int j = 0 ; j < priorities.size(); j++){
            if(priorities[i] < priorities[j])
                lo[i]++;
        }
        list.push({priorities[i], i});
    }
    
    int pr = 0;
    while(!list.empty()){
        int temp_val = list.front().first;
        int temp_lo = list.front().second;
        list.pop();
        
        if(lo[temp_lo]==0){
            for(int i = 0 ; i < priorities.size(); i++){
            if(priorities[i] < temp_val)
                lo[i]--;
        }
            
            pr++;
            index[temp_lo]=pr;
            continue;
        }
        
        
        list.push({temp_val, temp_lo});
    }

    answer=index[location];
    return answer;
}