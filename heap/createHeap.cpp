#include<iostream>
using namespace std;

class heap{
  public:
    int arr[100];
    int size;

    heap(){
      arr[0]=-1;
      size=0;
    }

    /* insertion in heap*/ 
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


    /*Deletion From Heap*/
    void deleteFromHeap(){
      if(size==0){
        cout<<"nothing to delete";
        return;
      }else{
        int x,i,j;
        x=arr[1];
        arr[1]=arr[size];
        i=1;j=2*i;

        while(j<size-1){
          if(arr[j+1]>arr[j]){
            j=j+1;
          }
          if(arr[i]<arr[j]){
            swap(arr[i],arr[j]);
            i=j;
            j=2*j;
          }else{
            break;
          }

        }
        arr[size]=x;
      }
    }
};



int main(){
  heap h;
  h.insert(10);
  h.insert(20);
  h.insert(30);
  h.insert(25);
  h.insert(5);
  h.insert(40);
  h.insert(35);
  // h.deleteFromHeap();
  h.print();
}