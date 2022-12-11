#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class DLL{
    node* head;
    public:
        DLL(){
            head=NULL;
        }
        void insertAtTail(int val){
            if(head==NULL){
                insertAtHead(val);
                return;
            }
            node* n=new node(val);
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
            display();
        }
        void insertAtHead(int val){
            node* n=new node(val);
            n->next=head;
            if(head!=NULL){
                head->prev=n;
            }
            head=n;
            display();
        }
        void insertAtIPosition(int val,int key){
            if(key==1){
                insertAtHead(val);
                return;
            }
            node* n=new node(val);
            int i=1;
            node* temp=head;
            while(temp->next!=NULL){
                i++;
                if(i==key) break;
                temp=temp->next;
            }
            n->next=temp->next;
            temp->next->prev=n;
            temp->next=n;
            n->prev=temp;
            display();
        }
        void deleteAtHead(){
            node* toDelete=head;
            head=head->next;
            head->prev=NULL;
            delete toDelete;
            display();
        }
        void deleteAtTail(){
            if(head==NULL){
                return;
            }
            if(head->next==NULL){
                deleteAtHead();
                return;
            }
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            node* toDelete=temp;
            temp->prev->next=NULL;
            delete toDelete;
            display();
        }
        void deleteAtIPosition(int key){
            if(key==1){
                deleteAtHead();
                return;
            }
            node* temp=head;
            int i=1;
            while(temp!=NULL && i!=key){
                temp=temp->next;
                i++;
            }
            temp->prev->next=temp->next;
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }
            delete temp;
            display();
        }
        node* search(int key){
            node* temp=head;
            while(temp!=NULL){
                if(temp->data==key){
                    return temp;
                }
                temp=temp->next;
            }
            return NULL;
        }
        void concatenate(DLL &d2){
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=d2.head;
            d2.head->prev=temp;
            cout << "Linked List after Concatenate :";
            display();
        }
        void display(){
            node* temp=head;
            cout << "NULL <-> ";
            while(temp!=NULL){
                cout << temp->data << " <-> ";
                temp=temp->next;
            }
            cout << "NULL\n\n";
        }
};
int main(){
    DLL obj,obj2;
    int c;
    char ch='Y';
    do{
        cout << "1.insert at head\n2.insert at tail\n3.insert at i position\n";
        cout << "4.delete at head\n5.delete at tail\n6.delete at i position\n";
        cout << "7.search an element\n8.concatenate two doubly linked list\n";
        cout << "Enter your choice :";
        cin >> c;
        switch(c){
            case 1:
                int k;
                cout << "Enter element to insert :";
                cin >> k;
                obj.insertAtHead(k);
                break;
            case 2:
                cout << "Enter element to insert :";
                cin >> k;
                obj.insertAtTail(k);
                break;
            case 3:
                int i;
                cout << "Enter element to insert :";
                cin >> k;
                cout << "Enter position of element :";
                cin >> i;
                obj.insertAtIPosition(k,i);
                break;
            case 4:
                obj.deleteAtHead();
                break;
            case 5:
                obj.deleteAtTail();
                break;
            case 6:
                cout << "Enter position to be deleted :";
                cin >> i;
                obj.deleteAtIPosition(i);
                break;
            case 7:
                cout << "enter an element to search";
                cin >> k;
                if(obj.search(k)==NULL){
                    cout << "Element Not Found...\n\n";
                }
                else cout << "Element Found...\n\n";
                break;
            case 8:
                cout << "Enter no. of element in second linked list :";
                cin >> i;
                for(int j=1;j<=i;j++){
                    cout << "enter element "<< j << " :";
                    cin >> k;
                    obj2.insertAtTail(k);   
                }
                obj.concatenate(obj2);
                break;
            default:
                cout << "Wrong Choice!!!";
        }
    }while(ch=='Y' || ch=='y');
}