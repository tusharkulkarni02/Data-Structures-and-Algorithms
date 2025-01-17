#include <bits/stdc++.h>
using namespace std;

void Merge(int input1[],int input2[],int m, int n){

    int k=0,i=0,j=0;
    int merged[m+n];
    while (i<m && j<n){
        if (input1[i]<=input2[j]){
            merged[k]=input1[i];
            i++;
            k++;
        }
        else if (input1[i]>=input2[j]){
            merged[k]=input2[j];
            j++;
            k++;
        }
    }
    while(i<m){
        merged[k]=input1[i];
        i++;
        k++;
    }
    while(j<n){
        merged[k]=input2[j];
        j++;
        k++;
    }

    

    cout << "Merge sorted array is:";
    for (int i=0; i<m+n;i++){
        cout << merged[i] << " ";
    }
}

int main(){
    int m , n;
    cout <<"Enter n & m:" << endl;
    cin >> m >> n;
    int input1[m] , input2[n];

    cout << "Enter elements of array 1:"<<endl;
    for (int i=0; i<m; i++){
        cin >> input1[i];
    }

    sort(input1,input1+m);

    cout << "Sorted array 1 is:" << endl;

    for (int i=0; i<m; i++){
        cout << input1[i] << " ";
    }

    cout << "Enter elements of array 2:"<<endl;

    for (int i=0; i<n; i++){
        cin >> input2[i];
    }
    sort(input2,input2+n);

    cout << "Sorted array 2 is:" << endl;

    for (int i=0; i<n; i++){
        cout << input2[i] << " ";
    }

    Merge(input1,input2,m,n);

}