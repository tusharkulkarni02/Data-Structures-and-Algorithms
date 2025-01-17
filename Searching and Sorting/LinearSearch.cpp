#include<iostream>
using namespace std;


int linearSearch( int arr[], int n, int value){
    
    for (int i=0; i<n; i++){
        if (arr[i]==value){
            return i;
        }
    }
    return -1;
}


int main(){
    int n;
    cin >> n;

    int value;
    cout << "Value: " << endl;
    cin >> value;

    int arr[100];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int result = linearSearch(arr, n, value);

    if (result != -1) {
        cout << "Value found at index: " << result << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}






