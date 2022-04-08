#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size+=1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
        
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout << arr[i] << " ";
            }
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing to delete "<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;

        //NOW PLACE IT TO ITS CORRECT POSITION
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i +1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
             }
             else if(rightIndex<size && arr[i]<arr[rightIndex]){
                 swap(arr[i],arr[rightIndex]);
                 i=rightIndex;
             }
             else{
                 return;
             }
        }
    }
   
};
 void heapify(int *arr,int n,int i){
        int largest=i;
        int leftChild=2*i;
        int rightChild=2*i+1;
        if(leftChild<n && arr[largest]<arr[leftChild])
            largest=leftChild;
        if(rightChild<n && arr[largest]<arr[rightChild])
            largest=rightChild;
        if(largest !=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.print();
    cout<<endl;
    h.deleteFromHeap();
    h.print();
    int arr[6]={-1,54,53,52,55,43};
    int n=5;
    for(int i=3;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing the array right now " << endl;
    for(int i=1;i<=5;i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;


}