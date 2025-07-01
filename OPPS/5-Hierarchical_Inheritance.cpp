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
        cout<<"B is called..\n";
    }
};
class C: public A{
    public:
    void c(){
        cout<<"C is called..\n";
    }
};
int main(){
    A a;
    B b;
    C c;
    a.a(); //A is called..
    b.b(); //B is called..
    c.c(); //C is called..
    c.a(); //A is called..
    b.a(); //A is called..
    return 0;
}