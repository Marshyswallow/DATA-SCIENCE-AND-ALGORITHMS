#include <iostream>
#include <algorithm> 
using namespace std;


int binarySearch(int arr[], int key, int n) {
    sort(arr,arr+n);
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}



int main() {

    int n, key;
    cout<<"Enter the size of array and key to be searched: ";
    cin >> n >> key;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << binarySearch(arr, key, n); /* result obtained is 
                                                after array sorted*/

}