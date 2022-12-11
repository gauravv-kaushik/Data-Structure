#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
};
class queue{
    private:
        node* head;
    public:
        queue(){
            head=NULL;
        }
        void enqueue(int val){
            node* n=new node(val);
            if(head==NULL){
                n->next=n;
                head=n;
                display();
                return;
            }
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=n;
            n->next=head;
            display();
        }
        void dequeue(){
            if(head==NULL){
                cout << "queue is empty!!!\n";
                return;
            }
            node* toDelete=head;
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=head->next;
            head=head->next;
            delete toDelete;
            display();
        }
        int frontel(){
            return head->data;
        }
        bool isempty(){
            return head==NULL;
        }
        int size(){
            node* temp=head;
            int c=1;
            while(temp->next!=head){
                c++;
                temp=temp->next;
            }
            return c;
        }
        void display(){
            if(head==NULL) return;
            node* temp=head;
            cout << "Linked List is :\n";
            do{
                cout << temp->data << " ";
                temp=temp->next;
            }while(temp!=head);
            cout << "\n";
        }
};
int main(){
    int c;
    char ch;
    queue obj;
    do{
        cout << "1.enqueue \n2.dequeue \n3.front element \n4.size \n5.isempty\n";
        cout << "enter your choice :";
        cin >> c;
        switch(c){
            case 1:
                int k;
                cout << "enter a element :";
                cin >> k;
                obj.enqueue(k);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                if(obj.frontel()==NULL)   cout << "queue is empty\n\n";
                else   cout << "front element is "<<obj.frontel() << "\n\n";
                break;
            case 4:
                cout << "size of queue is "<< obj.size() << "\n\n";
                break;
            case 5:
                if(obj.isempty()) cout << "queue is empty\n\n";
                else cout << "queue is not empty\n\n";
                break;
        }
        ch='Y';
    }while(ch=='y' || ch=='Y');
}