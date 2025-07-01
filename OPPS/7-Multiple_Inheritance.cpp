#include<iostream>
using namespace std;
class A{
    public:
    void a(){
        cout<<"A is called..\n";
    }
};
class B {
    public:
    void b(){
        cout<<"B is called.\n";
    }
};
class C : public A,public B{
    public:
    void c(){
        cout<<"C is called.\n";
    }
};
int main(){
    A a;
    a.a();   //A is called
    B b;
    b.b();  //B is called
    C c;
    c.a();  //A is called
    c.b();  //B is called
    c.c();  //C is called
    return 0;
}