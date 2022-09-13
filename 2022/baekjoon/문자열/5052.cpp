//5052 전화번호 목록
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string phone[n];
        for(int i = 0 ; i < n ; i++){
            cin >> phone[i];
        }
        sort(phone, phone + n);

        string compare = phone[0];
        
        bool consistent = true;
        for(int i = 1 ; i < n ; i++){
            bool check;
            if(compare.length() > phone[i].length()){
                check = (compare.substr(0, phone[i].length()) == phone[i]);
            }else{
                check = (compare == phone[i].substr(0, compare.length()));
            }
            
            if(check){
                cout << "NO\n";
                consistent = false;
                break;
            }
            compare = phone[i];

        }
        
        if(consistent){
            cout << "YES\n";
        }
        
    }
    
    return 0;
}