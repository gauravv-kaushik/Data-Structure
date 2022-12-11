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
class stack{
    node* head;
    public:
    stack(){
        head=NULL;
    }
    void push(int val){
        node* n=new node(val);
        n->next=head;
        head=n;
        cout << "Element added...\n\n";
    }
    void pop(){
        if(head==NULL){
            cout << "Stack is empty...\n\n";
            return;
        }
        node* toDelete=head;
        head=head->next;
        delete toDelete;
        cout << "Element deleted...\n\n";
    }
    int topp(){
        if(head!=NULL) return head->data;
        else return-1024;
    }
    bool isempty(){
        return head!=NULL;
    }
    int sizee(){
        int count=0;
        node* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void display(){
        node* temp=head;
        cout << "\nstack is :\n";
        while(temp!=NULL){
            cout << temp->data << endl;
            temp=temp->next;
        }
        cout << endl;
    }
};
int main(){
    stack obj;
    int c;
    char ch='Y';
    do{
        cout << "1.push\n2.pop\n3.top\n4.isempty\n5.size\n6.display\n";
        cout << "Enter your choice :";
        cin >> c;
        switch(c){
            case 1:
                int k;
                cout << "Enter a value :";
                cin >> k;
                obj.push(k);
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                if(obj.topp()==-1024) cout << "Stack is empty!!!\n\n";
                else cout << "element at top is " << obj.topp() << "\n\n";
                break;
            case 4:
                if(obj.isempty()) cout << "stack is not empty...\n\n";
                else cout << "stack is empty...\n\n";
                break;
            case 5:
                cout << "size of stack is " << obj.sizee() << "\n\n";
                break;
            case 6:
                obj.display();
                break;
            default:
                cout << "You have entered wrong choice\n\n";
        }
    }while(ch=='Y' || ch=='y');
}