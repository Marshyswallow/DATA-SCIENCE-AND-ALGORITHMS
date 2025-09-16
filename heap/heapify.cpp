#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
  int largest=i;
  int left=2*i;
  int right=2*i+1;

  if(left<n && arr[largest]<arr[left])largest=left;
  if(right<n && arr[largest]<arr[right])largest=right;
  if(largest!=i){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}


/*HEAP SORT*/
void heapSort(int arr[],int n){
  int size=n;
  while(size>1){
    swap(arr[size],arr[1]);
    size--;
    heapify(arr,size,1);
  }
}
int main(){
  int h[]={0,10,20,30,25,5,40,35};
  int n=sizeof(h)/sizeof(h[0]);

  for(int i=n/2;i>0;i--){
    heapify(h,n,i);
  }

  for(int i:h){
    cout<<i<<" ";
  }cout<<endl;

  heapSort(h,n-1);
  
  for(int i:h){
    cout<<i<<" ";
  }cout<<endl;


}