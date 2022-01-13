#include <iostream>
#include <string>
using namespace std;
int stack[10001];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    if(top == -1)
        return -1;
    return stack[top--];
}

int size() {
    return top + 1;
}

int empty() {
    if(top == -1) return 1;
    return 0;
}
int s_top() {
    if(top == -1) return -1;
    return stack[top];
}

int main() {
    int N;
    cin >> N;
    while (N--){
        string order;
        cin >> order;
        if (order == "pop"){
            cout << pop() << "\n";
        }else if (order=="size"){
            cout << size() << "\n";
        }else if (order=="empty") {
            cout << empty() << "\n";
        }else if(order=="top"){
            cout << s_top() << "\n";
        }else { //push
           int X;
           cin >> X;
           push(X);
        }
    }

    return 0;
}