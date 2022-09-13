#include <iostream>
#include <algorithm>
using namespace std;


int home[200001];
int ans = 0;

void binary_search(int n, int c){
    
    int l = 0;
    int r = home[n-1] - home[0];
    
    while(1){
        if(l > r){
            return;
        }
        
        int mid = (l + r) / 2;
        // 거리를 mid 이상으로 해서 몇개의 공유기를 설치할 수 있는가?
        int count = 1;
        
        int compare = home[0];
        for(int i = 1 ; i < n ; i ++){
            if(home[i] - compare >= mid){
                count++;
                compare = home[i];
            }
            
        }
        
        
        if(count < c){ //설치할 수 없다. 거리를 줄이자.
            r = mid - 1;
        }else{ //설치할 수 있다. 거리를 늘린다.
            l = mid + 1;
            ans = max(ans, mid);
        }
        
    }
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    
    for(int i = 0 ; i < n ; i++){
        cin >> home[i];
    }
    sort(home, home + n);
    
    binary_search(n, c);
   
    cout << ans;
    
    return 0;
}