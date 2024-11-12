#include<iostream>
using namespace std;
int max1, min1;
void getarr(int arr[], int n){
	for(int i = 0;i < n; i++){
		cout<<"Enter array element"<<i +1 <<":";
		cin>>arr[i];
	}
}
void printarr(int arr[], int n){
	for(int i = 0;i < n; i++){
		cout<<arr[i]<<" ";
		
	}
	cout<<endl;
}

void minMax(int arr[], int i, int j){
	int max2, min2;
	if(i == j){
		max1 = min1= arr[i];
	}
	else{
		if(i == j-1){
			if(arr[i] < arr[j]){
				max1 = arr[j];
				min1 = arr[i];
			}
			else{
				max1 = arr[i];
				min1 = arr[j];
			}
		}
		else{
			int mid = (i+j)/2;
			minMax(arr, i, mid);
			max2 = max1 ;
			min2 = min1 ;
			minMax(arr, mid+1, j);
			if(max1< max2) max1 = max2;
			if(min1> min2) min1 = min2;
		
		}
	}
}

int main(){
	int n;
	int arr[n];
	cout<<"Enter the size of array: ";
	cin>>n;
	getarr(arr, n);
	cout<<"array";
	printarr(arr, n);
	minMax(arr, 0, n-1);
	cout<<"THe max element is : "<< max1 <<endl;
	cout<<"The min element is : "<< min1 <<endl;
	return 0;
	T(n)=2T(n/2)+2;
	complexity of this code is O(n).
}

