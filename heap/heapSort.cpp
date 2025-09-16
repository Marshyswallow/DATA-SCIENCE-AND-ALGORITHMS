#include<iostream>
using namespace std;

void insert(int h[],int n){
  int i=n,temp;
  temp=h[i];

  while(i>1 && temp>h[i/2]){
    h[i]=h[i/2];
    i=i/2;
  }
  h[i]=temp;
}

void deleteFromHeap(int a[],int n){
  int i,j,x;
  x=a[1];
  a[1]=a[n];
  i=1;j=i*2;

  while(j<n-1){
    if(a[j+1]>a[j]){
      j=j+1;

    }
    if(a[i]<a[j]){
      swap(a[i],a[j]);
      i=j;
      j=j*2;
    }else{
      break;
    }
  }
  a[n]=x;
}

/*HEAPIFY*/
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[largest]<arr[left]){
      largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
      largest=right;
    }

    if(largest!=i){
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
    }
}

int main(){
  int h[]={0,10,20,30,25,5,40,35};
  int n=sizeof(h)/sizeof(h[0]);
  // for(int i=1;i<n;i++){
  //   insert(h,i);
  // }
  // for(int i=n-1;i>1;i--){
  //   deleteFromHeap(h,i);
  // }

  // for (int i=1;i<n;i++){
  //   cout<<h[i]<<" ";
  // }cout<<endl;
// for(int i=n/2;i>0;i--)
//   heapify(h,n,i);
//   for(int i:h){
//     cout<<i<<" ";
//   }cout<<endl;


}