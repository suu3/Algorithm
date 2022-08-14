#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int sum[n];
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            cin >> sum[i];
        }else{
            cin >> sum[i];
            sum[i] += sum[i-1];
        }
    }

    for(int i = 0 ; i < m ; i++){
        int start, end;
        cin >> start >> end;
        if(start==1){
            cout << sum[end-1] << "\n";
        }else{
            cout << sum[end-1] - sum[start-2] << "\n";
        }
    }

    return 0;
}