//18258 큐 2

//생각할점: 공백까지 입력으로 받는 getline

#include <iostream>

using namespace std;

int queue[2000001];
int front = 0;
int roar = 0;

bool empty(){
    if(front == roar){
        return true;
    }else{
        return false;
    }
}


void push(int X){ // 뒤에 추가한다
    queue[roar] = X;
   // cout << queue[roar] << "\n";
    roar++;
}

void pop(){ // 앞에서 뺀다
    if(empty()){ // 정수가 없는 경우
        cout << "-1" << "\n";
        return;
    }
    cout << queue[front] << "\n";
    front++;
}

void size(){
    cout << roar - front << "\n";
}

void print_front(){
    if(empty()){
        cout << "-1" << "\n";
        return;
    }
    
    cout << queue[front] << "\n";
    
}

void back(){
    if(empty()){
        cout << "-1" << "\n";
        return;
    }
    
    cout << queue[roar-1] << "\n";
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        string command;
        cin >> command;

        if(command == "push"){
            int num;
            cin >> num;
            push(num);
            
        }else if(command=="pop"){
            pop();
        }else if(command=="front"){
            print_front();
        }else if(command=="back"){
            back();
        }else if(command=="size"){
            size();
        }else if(command=="empty"){
            if(empty()){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }
    }
    
    return 0;
}