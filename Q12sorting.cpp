#include <iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << "Array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << "Array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    cout << "Array after sorting :";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int c,n,k;
    char ch;
    cout << "Enter no. of elements in array :";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> k;
        arr[i]=k;
    }
    do{
        cout << "1.Bubble sort\n2.Selection sort\n3.Insertion sort\nEnter your choice :";
        cin >> c;
        switch(c){
            case 1:
                bubbleSort(arr,n);
                break;
            case 2:
                selectionSort(arr,n);
                break;
            case 3:
                insertionSort(arr,n);
                break;
        }
    }while(ch=='Y' or ch=='y');
}