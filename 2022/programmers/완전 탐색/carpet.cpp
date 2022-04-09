#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int row, col;
    
    //곱해서 brown + yellow가 나오는 두 수를 고른다.
    for(int i = 1 ; i <= sum ; i++){
        if(sum % i != 0) continue; //약수가 아니면 넘김
        
        row = i;
        col = sum / i;
        
        int check = (row - 2) * (col - 2);
        if(yellow == check && brown == sum - check){
            if(col > row){
                int temp = col;
                col = row;
                row = temp;
            }
            answer.push_back(row);
            answer.push_back(col);
            return answer;
        }
    }
    
    return answer;
}