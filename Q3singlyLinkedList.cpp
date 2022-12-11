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
class SLL{
    node* head;
    public:
    SLL(){
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
    void insertAtIposition(int index,int val){
        if(index==1){
            insertAtHead(val);
            return;
        }
        int i=1;
        node* temp=head;
        while(temp->next!=NULL){
            i++;
            if(i==index) break;
            temp=temp->next;
        }
        node* n=new node(val);
        n->next=temp->next;
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
    void deleteAtIposition(int index){
        if(index==1){
            deleteAtHead();
            return;
        }
        int i=1;
        node* temp=head;
        while(temp->next!=NULL){
            i++;
            if(i==index) break;
            temp=temp->next;
        }
        node* toDelete=temp->next;
        temp->next=temp->next->next;
        delete toDelete;
        display();
    }
    void deleteByValue(int key){
        if(head==NULL) return;
        if(head->next==NULL || head->data==key){
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
        node* temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
    void concatenate(SLL &s2){
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=s2.head;
        cout << "Linked List after Concatenate :";
        display();

    }
    void reverse(){
        node* prevptr=NULL;
        node* currptr=head;
        node* nxtptr;
        while(currptr!=NULL){
            nxtptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nxtptr;
        }
        head=prevptr;
        display();
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout << temp->data << " -> ";
            temp=temp->next;
        }
        cout << "NULL\n" << endl;
    }
};
int main(){ 
    SLL obj,obj2;
    int c;
    char ch='Y';
    do{
        cout << "1.insert at head\n2.insert at tail\n3.insert at i position\n";
        cout << "4.delete at head\n5.delete at tail\n6.delete at i position\n";
        cout << "7.search an element\n8.concatenate two singly linked list\n";
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
                obj.insertAtIposition(i,k);
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
                obj.deleteAtIposition(i);
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