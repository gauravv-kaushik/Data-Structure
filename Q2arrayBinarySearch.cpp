#include <iostream>
using namespace std;
class array{
    public:
        int binarySearch(int arr[],int low,int high,int key){
            int mid=(low+high)/2;
            if(arr[mid]==key) return mid;
            if(arr[mid]>key)  return binarySearch(arr,low,mid-1,key);
            else if(arr[mid]<key)  return binarySearch(arr,mid+1,high,key);
            else return -1;
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
    int result=obj.binarySearch(arr,0,size,key);
    if(result==-1) cout << key << " not present in array";
    else cout << key << " present in array at index " << result;
}