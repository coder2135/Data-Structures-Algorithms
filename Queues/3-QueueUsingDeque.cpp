#include<iostream>
#include<deque>
using namespace std;
class Queue{
    deque<int> dq;
public:
    void push(int val){
        dq.push_back(val);
    }
    void pop(){
        dq.pop_front();
    }
    bool empty(){
        return dq.size()== 0;
    }
    int front(){
        return dq.front();
    }
    int size(){
        return dq.size();
    }
};
int main(){
    Queue que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout<<que.front()<<" ";
    cout<<que.size()<<" ";
    return 0;
}