#include<iostream>
using namespace std;
class Node{
public:
   int data;
   Node* next;
   Node(int val){
    data = val;
    next = NULL;
   }
};
class Queue{
public : 
   Node* head;
   Node* tail;
   Queue(){
    head = tail = NULL;
   }
   //push_back
   void push(int val){
    Node* newNode = new Node(val);
      if(head == NULL){
        head = tail = newNode;
      }else{
        tail->next = newNode;
        tail = newNode;
      }
   }
   //pop_front
   void pop(){
    if(empty()){
        cout<<"Queue is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
   }
   //front
   int front(){
    if(empty()){
        cout<<"Queue is empty\n";
        return -1;
    }
    return head->data;
   }
   //isEmpty
   bool empty(){
    return head == NULL;
   }
   //size
   int size(){
    Node* temp = head;
    if(head == NULL && tail == NULL){
        return 0;
    }
    int count = 1;
    while(temp->next != NULL){
        count ++;
        temp = temp->next;
    }
    return count;
   }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"Size of Queue : "<<q.size()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}