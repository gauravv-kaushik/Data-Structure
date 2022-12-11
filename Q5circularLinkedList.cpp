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
class CLL{
    private:
        node* head;
    public:
        CLL(){
            head=NULL;
        }
        void insertAtHead(int val){
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
            head=n;
            display();
        }
        void insertAtTail(int val){
            if(head==NULL){
                insertAtHead(val);
                return;
            }
            node* n=new node(val);
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=n;
            n->next=head;
            display();
        }
        void insertAfterVal(int val,int key){
            node* n=new node(val);
            node* temp=head;
            while(temp->data!=key){
                temp=temp->next;
            }
            n->next=temp->next;
            temp->next=n;
            display();
        }
        void deleteAtHead(){
            if(head==NULL){
                cout << "Linked list is empty!!!";
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
        void deleteAtTail(){
            node* temp=head;
            while(temp->next->next!=head){
                temp=temp->next;
            }
            node* toDelete=temp->next;
            temp->next=head;
            delete toDelete;
            display();
        }
        void deleteByValue(int key){
            if(head->data==key){
                deleteAtHead();
                return;
            }
            node* temp=head;
            while(temp->next->data!=key){
                temp=temp->next;
            }
            node* toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            display();
        }
        node* search(int key){
            if(head->data==key){
                return head;
            }
            node* temp=head;
            while(temp->next!=head){
                if(temp->data==key){
                    return temp;
                }
                temp=temp->next;
            }
            return NULL;
        }
        void concatenate(CLL &c2){
            node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=c2.head;
            temp=c2.head;
            while(temp->next!=c2.head){
                temp=temp->next;
            }
            temp->next=head;
            cout << "Linked List after Concatenate :";
            display();
        }
        void display(){
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
    CLL obj,obj2;
    int c;
    char ch='Y';
    do{
        cout << "1.insert at head\n2.insert at tail\n3.insert after value\n";
        cout << "4.delete at head\n5.delete at tail\n6.delete a value\n";
        cout << "7.search an element\n8.concatenate two circular linked list\n";
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
                cout << "Enter a value of linked list :";
                cin >> i;
                obj.insertAfterVal(k,i);
                break;
            case 4:
                obj.deleteAtHead();
                break;
            case 5:
                obj.deleteAtTail();
                break;
            case 6:
                cout << "Enter a element to delete :";
                cin >> i;
                obj.deleteByValue(i);
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