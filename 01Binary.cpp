#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int low, int high) {
    int mid;
    while (low<=high) {
        mid = low + (high - low)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) high = mid - 1; 
        else low = mid + 1;
    }
    return -1;
}

int binarySearchRecursive (int arr[], int target, int low, int high) {
    int mid = low + (low - high)/2;
    if (low<=high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == target) return mid;
        else if (arr[mid] > target) binarySearchRecursive(arr, target, low, mid-1);
        else binarySearchRecursive(arr, target, mid+1, high);
    }
    else return -1;
}

int main() {
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int array[size], i = 0;
    
    while(i<size) {
    	cout<<"Enter element "<<i<<": ";
    	cin>>array[i];
    	i++;
	}
	
	int key;
	cout<<"Enter the element to be searched: ";
	cin>>key;
	
	int x;
	int idx;
	do {
		cout<<"1. Recursive "<<endl<<"2. Non-recursive"<<endl<<"3. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>x;
		switch(x) {
			case 1: idx = binarySearchRecursive(array, key, 0, size-1);
					(idx!=-1) ? cout<<"Number is present at index "<<idx<<endl : cout<<"Number is not present in the array";
					break;
			case 2: idx = binarySearch(array, key, 0, size-1);
    				(idx!=-1) ? cout<<"Number is present at index "<<idx<<endl : cout<<"Number is not present in the array";
    				break;
    		case 3: break;
    		default: cout<<"Invalid response.";
		}
	} while (x!=3);
    return 0;
}
