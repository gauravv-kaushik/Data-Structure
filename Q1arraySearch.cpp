#include <iostream>
using namespace std;
class array{
    public:
        int search(int arr[],int size,int key){
            for(int i=0;i<size;i++){
                if(arr[i]==key){
                    return i;
                }
            }
            return -1;
        }
};
int main(){
    array obj;
    int size,key;
    cout << "Enter size of array :";
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    cout << "Enter element you want to search :";
    cin >> key;
    int result=obj.search(arr,size,key);
    if(result==-1) cout << key << " not present in array ";
    else cout << key <<" found at index "<< result;
}