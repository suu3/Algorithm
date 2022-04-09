#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;

int answer = 0;
set<int> answer_set;
vector<bool> is_prime;

void isPrime(int n){
	is_prime[0] = is_prime[1] = false;
	for (int i = 2 ; i < sqrt(n) ; i++ ) {
		if(is_prime[i]){
			for(int j = i * i ; j <= n ; j += i){
				is_prime[j] = false;
			}
		}
	}
}
void permutation(string numbers, vector<char> selected, vector<bool> visited, int n, int r, int num) {
    if (num == r) {
        string str = "";
        for (int i = 0; i < r; i++) {
            str += selected[i];
        }
        int val = stoi(str);
        
        if(is_prime[val]){
            answer_set.insert(val);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if(!visited[i]){
            visited[i] = true;
            selected[num] = numbers[i];
            permutation(numbers, selected, visited, n, r, num + 1);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    is_prime.assign(pow(10,(numbers.length())) + 1 , true);
    isPrime(pow(10,(numbers.length())));
    
	
    for (int i = 1 ; i <= numbers.size() ; i++){
        vector<char> selected(i, 0);
        vector<bool> visited(numbers.length(), false);
        permutation(numbers, selected, visited, numbers.length(), i, 0);
    }
	
    answer = answer_set.size();
    for (auto iter = answer_set.begin() ; iter != answer_set.end(); iter++){
		cout << *iter << " ";
    }
    return answer;
}