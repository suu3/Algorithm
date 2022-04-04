#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<>());                                       
    //h가 꼭 citations에 있는 것은 아니다.
    int h = citations[0];
    while(h--){
        int count = 0;
        for(int j = 0 ; j < citations.size() ; j++){
            if(citations[j]<h)
                break;
            count++;
        }
        if(count>=h) return h;
    }
}
