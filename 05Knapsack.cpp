#include<iostream>
using namespace std;

class item {
	public:
		int weight;
		int profit;
		float ratio;
		float fraction;
		item() {
			fraction = 0.0;
		}
};
 
void bubbleSort(item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j+1].ratio) {
                item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

float solveKnapsack (int maxCap, item items[], int n) {
	bubbleSort(items, n);
	float maxProfit;
	float fractions[n];
	
	for (int i = 0; i<n; i++) {
		if (maxCap >= items[i].weight) {
            maxCap = maxCap - items[i].weight;
            maxProfit = maxProfit + items[i].profit;
            items[i].fraction = 1.0;
        } else {
            maxProfit = maxProfit + items[i].profit * ((float)maxCap/items[i].weight);
            items[i].fraction = (float)maxCap/items[i].weight;
            
            break;
        }
	}
	return maxProfit;
}

int main() {
	
	int n;
	cout<<"Enter the number of items: ";
	cin>>n;
	cout<<endl;
	
	item items[n];
	for (int i = 0; i < n; i++) {
        int weight, profit;
        cout<<"Enter weight of item "<<i+1<<": ";
        cin>>weight;
        cout<<"Enter profit of item "<<i+1<<": ";
        cin>>profit;
        items[i].weight = weight;
        items[i].profit = profit;
        items[i].ratio = (float)profit/weight;
        cout<<endl;
    }
    
    for (int i = 0; i<n; i++) {
		cout<<"Ratio of item "<<i+1<<": ";
		cout<<items[i].ratio<<endl;
	}
    
    int maxCap;
	cout<<"Enter the maximum capacity of the Knapsack: ";
	cin>>maxCap;
	
	float maxProfit = solveKnapsack(maxCap, items, n);
	cout<<"Maximum Profit in the Knapsack is: "<<maxProfit<<endl<<endl;
	for (int i = 0; i<n; i++) {
		cout<<"Fraction of item "<<i+1<<" in the Knapsack: ";
		cout<<items[i].fraction<<endl;
	}
	
	return 0;
}
