#include<iostream>
using namespace std;
int board [100][100];
int sol =1;

void printArr(int n){
	for(int i =0; i< n; i++){
		for(int j =0; j< n; j++){
			if(board [i] [j] == 1){
				cout<< j+1 <<" ";
			}
	}
	}
	cout<<endl;
}
bool isSafe(int row, int col, int n){
	for(int i= 0; i<row; i++){
	if(board[i][col]){
	  return false;
	}
	}
	
	for(int i = row, j = col; i >= 0 && j >= 0 ; i--, j--){
		if(board[i][j]){
	  return false;
	}
	}
	for(int i = row,j = col; i >= 0 && j< n; i--, j++){
			if(board[i][j]){
	  return false;
	}
	}

return true;
}
void solve(int row, int n){
	if(row == n){
		cout<<"Soltion"<<sol<<" :";
		sol++;
		printArr(n);
		return;
	}
	for(int col=0;col<n;col++){
		if(isSafe(row, col, n)){
			board[row][col] = 1;
			solve(row +1, n);
			board[row][col] = 0;
			
		}
	}
} 
int main(){
	int n ;
	do{
		cout<<" Enter the number of Q :";
		cin >> n;
		if(n <3){
			cout<<"Enter at least 3 Q";
		}
		
	} while(n< 3);
	for(int i =0;i<n; i++){
		for(int j=0;j<n;j++){
			board[i] [j] = 0;
		}
	}
	solve(0,n);
	return 0;
	
}
