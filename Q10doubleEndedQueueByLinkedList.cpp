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
class doubleQueue{
    private:
        node* head;
    public:
        doubleQueue(){
            head=NULL;
        }
        void insertAtHead(int val){
            node* n=new node(val);
            n->next=head;
            head=n;
            display();
        }
        void insertAtTail(int val){
            node* n=new node(val);
            if(head==NULL){
                head=n;
                display();
                return;
            }
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;
            display();
        }
        void deleteAtHead(){
            node* toDelete=head;
            head=head->next;
            delete toDelete;
            display();
        }
        void deleteAtTail(){
            node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            node* toDelete=temp->next;
            temp->next=NULL;
            delete toDelete;
            display();
        }
        int frontel(){
            if(head==NULL) return -1024;
            return head->data;
        }
        int size(){
            node* temp=head;
            int c=0;
            while(temp!=NULL){
                c++;
                temp=temp->next;
            }
            return c;
        }
        bool isempty(){
            return head==NULL;
        }
        void display(){
            if(head==NULL) return;
            node* temp=head;
            while(temp!=NULL){
                cout << temp->data << " -> ";
                temp=temp->next;
            }
            cout << "NULL\n" << endl;
        }
};
int main(){
    doubleQueue obj;
    char ch;
    int c,choice;
    do{
        cout << "1.enqueue \n2.dequeue \n3.front element \n4.size \n5.isempty\n";
        cout << "enter your choice :";
        cin >> c;
        switch(c){
            case 1:
                int k;
                cout << "enter a element :";
                cin >> k;
                cout << "\n1.enqueue at front\n2.enqueue at rear\nEnter your choice :";
                cin >> choice;
                if(choice==1) obj.insertAtHead(k);
                else obj.insertAtTail(k);
                break;
            case 2:
                cout << "\n1.dequeue from front\n2.dequeue from rear\nEnter your choice :";
                cin >> choice;
                if(choice==1) obj.deleteAtHead();
                else obj.deleteAtTail();
                break;
            case 3:
                if(obj.frontel()==-1024)   cout << "queue is empty\n\n";
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