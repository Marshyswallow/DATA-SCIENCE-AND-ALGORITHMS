#include<iostream>

using namespace std;

int linearSeach(int arr[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key;
    cout<<"Enter the size of array: ";
    cin >> n;
    cout<<"Enter the key to be searched: ";
    cin>> key;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << linearSeach(arr, key, n);
}