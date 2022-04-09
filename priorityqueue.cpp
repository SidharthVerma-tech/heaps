#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(5);
    pq.push(3);
    pq.push(7);
    cout << "Element at top is: "<< pq.top()<<endl;
    cout<<pq.size()<<endl;
    cout<<"After popping "<< endl;
    pq.pop();
    cout<<pq.size()<<endl;
    cout<<"Creating min heap: "<<endl;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(4);
    minHeap.push(1);
    cout<<minHeap.top()<<endl;
    return 0;

}