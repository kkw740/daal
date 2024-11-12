#include<iostream>
using namespace std;
int partion(int arr[], int l, int h){
	
	int pivot = arr[l];
	int i = l ; int j = h;
	while(i < j){
		while(arr[i] <= pivot && i < h){
			i++;
		}
		while(arr[j] > pivot && j > l){
			j--;
		}
		if( i < j ){
			swap(arr[i],arr[j]);
		}
		
			
		}
	
	swap(arr[l],arr[j]);
	return j;	
	}

void quick(int arr[], int l, int h){
	if (l < h){
	int  j = partion(arr, l, h);
	quick(arr, l, j - 1);
	quick(arr, j + 1, h);
}
}
void parr(int arr[], int size)
{
	for(int i =0;i<size;i++){
		cout<< arr[i] <<" ";
	}
	cout<<endl;
	}
	
	int main(){
		int n;
		cout<<"Enter the size of array :";
		cin>>n;
		int arr[n];
		for(int i =0;i<n;i++){
			cout<<"Elemens : ";
			cin>>arr[i];
		}
		
		quick(arr, 0,n-1);
		cout<<"Sorted array";
		parr(arr, n);
        return 0;
		timme com : nlog(n)
		space com : O(n)
		
		
		
	}
