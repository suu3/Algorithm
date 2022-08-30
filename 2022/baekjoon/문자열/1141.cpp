//1141 접두사
/**
 * 접두사 X집합인 부분집합의 최대 크기 = 길이 순서대로 접두사가 되는 집합의 개수
 * 예를 들어, {h, hi}, {hello}, {run, running}, {rerun} 여기서 원소 하나씩 뽑아 집합하나를 만들면 그게 최대 크기임
 * 주의할 점 : 집합을 묶을 때 {h, hi, hello} 이렇겐 안됨. hi랑 hello가 접두사 관계까 아니므로 원소 2개를 뽑을 수 있기 때문에.
 * 
 */
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(const string &w1, const string &w2){
    if(w1.length() != w2.length())
        return w1.length() < w2.length();
    return w1 < w2;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string word[n];
    for(int i = 0 ; i < n ; i++){
        cin >> word[i];
    }
    
    sort(word, word + n , cmp);

    queue<string> q;
    
    for(int i = 0 ; i < n ; i++){
        q.push(word[i]);
    }
    
    queue<string> temp;
    // 큐 두개를 사용하여 집합이 만들어지만 ans에 추가하고, 큐에서 집합을 제거했다.    
    int ans = 0;
    while(!q.empty() || !temp.empty()){
        string cur = q.front();
        ans++;
        q.pop();
        while(!q.empty()){
            string cmp = q.front();
            if(cur == cmp.substr(0, cur.length())){
                cur = cmp; //좀더 긴 단어로 cur 교체
            }else{
                temp.push(cmp);
            }
            q.pop();
        }
        
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        
    }

    cout << ans;
    return 0;
}