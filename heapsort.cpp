#include <iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size+=1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing to delete from Heap" << endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        //NOW PUTTING IT TO ItS CORRECT POSITION
        int i=1;
        while(i<size){
            int leftChild=2*i;
            int rightChild=2*i+1;
            if(leftChild<size && arr[leftChild]>arr[i])
            {
                swap(arr[leftChild],arr[i]);
                i=leftChild;
            }
            else if(rightChild<size && arr[rightChild]>arr[i])
            {
                swap(arr[rightChild],arr[i]);
                i=rightChild;
            }
            else{
                return ;
            }


        }

    }
};
void heapify(int *arr,int i,int n){
    int largest=i;
    int leftChild=2*i;
    int rightChild=2*i+1;
    if(leftChild<=n && arr[leftChild]>arr[largest])
    largest=leftChild;
    if(rightChild<=n && arr[rightChild]>arr[largest])
    largest=rightChild;
    if(largest !=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }


}
void heapSort(int *arr,int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
    Heap h;
    h.insert(45);
    h.insert(50);
    h.insert(55);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.print();
    cout<<"After deletion "<<endl;
    h.deleteFromHeap();
    h.print();
    int arr[7]={-1,42,56,43,21,67,40};
    int n=6;
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
    cout<<"Now printing the array" << endl;
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"After Heapsort " << endl;
    int i=1;
    heapSort(arr,n);
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
}