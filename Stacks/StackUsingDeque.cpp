#include<iostream>
#include<deque>
using namespace std;
class Stack{
    deque<int> s;
public: 
    void push(int val){
        s.push_front(val);
    }
    void pop(){
        s.pop_front();
    }
    bool empty(){
        return s.size()==0;
    }
    int size(){
        return s.size();
    }
    int top(){
        return s.front();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<" \n";
    cout<<s.size()<<" \n";
    return 0;
}