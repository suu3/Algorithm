#include<iostream>
#include<string.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S;
    cin >> S;
    int alpha[26][S.length() + 1];
    memset(alpha, -1, sizeof(alpha));

    int q;
    cin >> q;
    while(q--){
        char a;
        int l, r;
        cin >> a >> l >> r;
        int index = a - 'a';

        alpha[index][0] = 0;

        if(alpha[index][1] !=-1){
            cout << alpha[index][r + 1] - alpha[index][l] << "\n";
            continue;
        }


        for(int i = 0 ; i < S.length() ; i++){
            alpha[index][i+1] = alpha[index][i];

            if(S[i]==a){
                alpha[index][i+1]++;
            }
        }

        cout << alpha[index][r + 1] - alpha[index][l] << "\n";
    }

    return 0;
}