#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n){

    for (int i=0; i<n; i++){
        int min = arr[i] , minindex = i;
        for (int j = i+1; j<n; j++){
            if (arr[j]<min){
                min = arr[j];
                minindex = j;
            }
        }

        //Swapping
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex]=temp;
    }

}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    SelectionSort(arr, n);

    cout << "Sorted array:" << endl;
    for (int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
}