#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Node{
public:
   int data;
   Node* next ;
   Node(int val){
    data = val;
    next = NULL;
   }
};
class List{
public: 
   Node* head;
   Node * tail;
   List(){
    head = NULL;
    tail =  NULL;
   }
   void push_back(int val){
    Node * newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
   }
   void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
   }
};
Node* merge(Node* head,Node* righthead){
    List ans;
    Node* i = head;
    Node* j = righthead;
    while(i!=NULL && j!= NULL){
        if((i->data) <= (j->data)){
            ans.push_back(i->data);
            i = i->next;
        }else{
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while(i!=NULL){
        ans.push_back(i->data);
        i = i->next;
    }
    while(j!=NULL){
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}
Node* splitAtMit(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev!=NULL){
        prev->next = NULL;
    }
    return slow;
}
Node* mergesort(Node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    Node* righthead = splitAtMit(head);
    Node * left = mergesort(head);
    Node * right = mergesort(righthead);
    return merge(left,right);
}
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(5);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(6);
    cout<<"Original list : ";
    ll.print();
    ll.head = mergesort(ll.head);
    cout<<"Sorted list : ";
    ll.print();
    return 0;
}