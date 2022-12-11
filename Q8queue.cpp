#include <iostream>
using namespace std;
class queue{
    private:
        int* arr;
        int front;
        int rear;
        int size;
        int count;
    public:
        queue(int n){
            arr=new int[n];
            front=0;
            rear=0;
            size=n;
            count=0;
        }
        void enqueue(int);
        void dequeue();
        int frontel();
        int sizee();
        bool isempty();
};
void queue :: enqueue(int val){
    if(count >= size){
        cout << "queue is full\n\n";
    }
    else{
        arr[rear]=val;
        rear=(rear+1)%size;
        count++;
        cout << "element added\n\n";
    }
}
void queue :: dequeue(){
    if(count==0){
        cout << "queue is empty\n\n";
    }
    else{
        front=(front+1)%size;
        count--;
        cout << "element deleted\n\n";
    }
}
int queue :: frontel(){
    if(count==0){
        return -1024;
    }
    else{
        return arr[front];
    }
}
int queue :: sizee(){
    return count;
}
bool queue :: isempty(){
    return count==0;
}

int main(){
    int n,c;
    char ch;
    cout << "enter size of array :";
    cin >> n;
    queue obj(n);
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
                if(obj.frontel()==-1024)   cout << "queue is empty\n\n";
                else   cout << "front element is "<<obj.frontel() << "\n\n";
                break;
            case 4:
                cout << "size of queue is "<< obj.sizee() << "\n\n";
                break;
            case 5:
                if(obj.isempty()) cout << "queue is empty\n\n";
                else cout << "queue is not empty\n\n";
                break;
        }
        ch='Y';
    }while(ch=='y' || ch=='Y');
}