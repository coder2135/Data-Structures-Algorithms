#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> vec;
public: 
    //PUSH FUNCTION
    void push(int val){
        vec.push_back(val);
        int x = vec.size()-1; //New element index
        int parI = (x-1)/2;  // Its parent index
        while(parI>=0 && vec[x]>vec[parI]){
            swap(vec[x],vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }
    //heapify function to fix CBT
    void heapify(int i){
        if(i >= vec.size()){
            return ;
        }
        int l = 2*i+1;
        int r = 2*i+2;
        int maxI = i;
        if(l < vec.size() && vec[l] > vec[maxI]){
            maxI = l;
        }
        if(r < vec.size() && vec[r] > vec[maxI]){
            maxI = r;
        }
        swap(vec[i],vec[maxI]);
        if(maxI != i){
            heapify(maxI);
        }
    }
    //POP FUNCTION
    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }
    //TOP FUNCTION
    int top(){
        return vec[0];
    }
    //EMPTY FUNCTION
    bool isEmpty(){
        return vec.size()==0;
    }
    //SIZE FUNCTION
    int size(){
        return vec.size();
    }
};
int main(){
    Heap heap;
    heap.push(10);
    heap.push(20);
    heap.push(11);
    heap.push(131);
    heap.push(111);
    while(!heap.isEmpty()){
        cout<<"Top : "<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}