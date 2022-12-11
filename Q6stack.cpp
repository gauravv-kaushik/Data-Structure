#include <iostream>
using namespace std;
class stack{
    private:
        int* arr;
        int top;
        int size;
    public:
        stack(int n){
            arr=new int[n];
            top=-1;
            size=n;
        }
        void push(int);
        void pop();
        int topp();
        bool isempty();
        int sizee();
        void display();
};
void stack :: push(int val){
    if(top>=size-1){
        cout << "Stack Overflow!!\n\n";
    }
    else{
        arr[++top]=val;
        cout << "Element Added...\n\n";
    }
}

void stack :: pop(){
    if(top==-1){
        cout << "Stack Underflow!!\n\n";
    }
    else{
        top--;
        cout << "Element Deleted...\n\n";
    }
}

int stack :: topp(){
    return arr[top];
}

bool stack :: isempty(){
    return top==-1;
}

int stack :: sizee(){
    return top+1;
}

void stack :: display(){
    for(int i=top;i>=0;i--){
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main(){
    int n,c;
    char ch;
    cout << "Enter size of array :";
    cin >> n;
    stack obj(n);
    do{
        cout << "1.push \n2.pop \n3.top \n4.isempty \n5.size \n6.display\n";
        cout << "Enter your choice :";
        cin >> c;
        switch(c){
            case 1:
                int val;
                cout << "enter a value :";
                cin >> val;
                obj.push(val);
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                cout << "element on top is " << obj.topp() << "\n\n";
                break;
            case 4:
                if(obj.isempty()) cout << "stack is empty\n\n";
                else cout << "stack is not empty\n\n";
                break;
            case 5:
                cout << "no. of elements in stack is "<< obj.sizee() << "\n\n";
                break;
            case 6:
                obj.display();
                break;
        }
        ch='Y';
    }while(ch=='Y' || ch=='y');
}