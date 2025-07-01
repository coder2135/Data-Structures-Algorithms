#include<iostream>
using namespace std;
class A{
    public:
    void a(){
        cout<<"A is called..\n";
    }
};
class B : public A{
    public:
    void b(){
        cout<<"B is called.\n";
    }
};
int main(){
    A a;
    a.a();   //A is called
    B b;
    b.b();  //B is called
    b.a();  //A is called
    return 0;
}