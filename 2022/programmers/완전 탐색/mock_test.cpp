#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    //큐 만들기
    queue<int> first;
    queue<int> second;
    queue<int> third;
    for(int i = 0 ; i < 5 ; i++){
        first.push(i+1);        
    }
    for(int i = 0 ; i < 5 ; i++){
        if(i+1 ==2)
            continue;
        second.push(2);
        second.push(i+1);        
    }
    third.push(3);
    third.push(3);
    for(int i = 0 ; i < 5 ; i++){
        if(i+1 ==3)
            continue;
        third.push(i+1);        
        third.push(i+1);        
    }
    
    // 계산
    int max_value = 0;
    int first_answer = 0;
    int second_answer =0;
    int third_answer = 0; // 맞은 문제 수
    for(int i = 0 ; i < answers.size() ; i++){
        int first_front = first.front();
        int second_front = second.front();
        int third_front = third.front();
        first.pop();
        second.pop();
        third.pop();
        
        if(answers[i]==first_front) first_answer++;
        if(answers[i]==second_front) second_answer++;
        if(answers[i]==third_front) third_answer++;
        
        first.push(first_front);
        second.push(second_front);
        third.push(third_front);
    }
    
    max_value = max(third_answer, max(first_answer, second_answer));
    if(max_value==first_answer) answer.push_back(1);
    if(max_value==second_answer) answer.push_back(2);
    if(max_value==third_answer) answer.push_back(3);
    return answer;
}