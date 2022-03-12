#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution_answer(vector<string> phone_book){
    for(int i = 0 ; i < phone_book.size()-1 ; i++){
        string left = phone_book[i];
        string right = phone_book[i+1];
        if(left==right.substr(0, left.length())){
            return false;
        }
    }
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    answer = solution_answer(phone_book);
    return answer;
}