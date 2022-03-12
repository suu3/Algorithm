#include <string>
#include <vector>
#include <map>

using namespace std;


int solution_answer(vector<vector<string>> clothes){
    map<string, int> clothes_list;
    vector<string> type_list;
    
    for(int i = 0; i < clothes.size() ; i++){
        string name = clothes[i][0];
        string type = clothes[i][1];

        if(clothes_list[type]==0){
            type_list.push_back(type);
        }
        clothes_list[type]++;
    }

    int answer = 1;
    
    for(int i = 0 ; i < type_list.size() ; i++){
        answer *= (clothes_list[type_list[i]]+1);
    }

    return answer-1;
}

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    answer = solution_answer(clothes);
    return answer;
}