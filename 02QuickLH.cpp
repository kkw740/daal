#include <iostream>
using namespace std;

// Partition function using pivot as the first element
int partitionLow(int arr[], int l, int h) {
    int pivot = arr[l]; 
    int i = l + 1, j = h;
    
    while (i <= j) {
        while (i <= h && arr[i] <= pivot) i++;
        while (j >= l && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

// Partition function using pivot as the last element
int partitionHigh(int arr[], int l, int h) {
    int pivot = arr[h]; 
    int i = l - 1;
    
    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int l, int h, int pivotChoice) {
    if (l < h) {
        int p;
        if (pivotChoice == 1)
            p = partitionLow(arr, l, h); // Use first element as pivot
        else
            p = partitionHigh(arr, l, h); // Use last element as pivot

        quickSort(arr, l, p - 1, pivotChoice);
        quickSort(arr, p + 1, h, pivotChoice);
    }
}

// Print array function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    int pivotChoice, printChoice;
    
    do{
	
    
    cout << "Choose pivot:\n1. First element\n2. Last element \n3. Exit \nEnter choice: ";
    cin >> pivotChoice;

            quickSort(arr, 0, n - 1, pivotChoice);
            cout << "Sorted array: ";
            printArray(arr, n);
            } while(pivotChoice != 3);
    
    return 0;
}

