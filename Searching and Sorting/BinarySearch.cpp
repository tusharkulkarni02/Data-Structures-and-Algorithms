#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int value){
    int start = 0 , end = n-1;
    while (start <=end){
        int mid = (start + end)/2;
        if (value == arr[mid]){
            return mid;
        }else if (value > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return -1;

}


int main(){

    int n;
    cin >> n;

    int arr[n];

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int value;
    cout << "Value:" << endl;
    cin >> value;

    int result = BinarySearch(arr, n, value);

    if (result != -1){
        cout << "index is:" << result << endl;
    }
    else {
        cout << "NO. not present" << endl;
    }

    return 0;

}