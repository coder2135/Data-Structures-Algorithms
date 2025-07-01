#include<iostream>
#include<stack> //Last In First Out(LIFO)
using namespace std;
void pushAtBottom(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return ;
    }
    int tope = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(tope);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<endl;
    pushAtBottom(s,0);
    cout<<"stack after updates : ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}