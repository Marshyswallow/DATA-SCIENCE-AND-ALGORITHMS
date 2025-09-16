#include<iostream>
using namespace std;  

void printRev(string str,int idx){
    if(str.length()<=idx){
        return ;
    }
    printRev(str,idx+1);
    cout<<str[idx];
    
}

int main(){
    string str = "abcd";
    printRev(str,0);
    return 0;
}