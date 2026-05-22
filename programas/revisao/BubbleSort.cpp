#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void exibirArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void){
    int array[10] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};

    cout << "Array original:" << endl;
    exibirArray(array, 10);

    bubbleSort(array, 10);

    cout << "Array ordenado:" << endl;
    exibirArray(array, 10);

    return 0;
}
