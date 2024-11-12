#include <iostream> 
#include <climits> 
using namespace std; 
 
int** distanceMatrix; 
int** dpTable;        
int numCities;       
 
int findMinCost(int currentCity, int visitedMask) { 
    if (visitedMask == (1 << numCities) - 1) 
        return distanceMatrix[currentCity][0]; 
 
    if (dpTable[currentCity][visitedMask] != -1) 
        return dpTable[currentCity][visitedMask]; 
 
    int minCost = INT_MAX;
 
    for (int nextCity = 0; nextCity < numCities; nextCity++) { 
        if ((visitedMask & (1 << nextCity)) == 0) { 
            int cost = distanceMatrix[currentCity][nextCity] +  
                       findMinCost(nextCity, visitedMask | (1 << nextCity));
            minCost = min(minCost, cost);
        } 
    } 
 
    return dpTable[currentCity][visitedMask] = minCost;
} 
 
void printPath(int currentCity, int visitedMask) { 
    cout << currentCity + 1;
 
    if (visitedMask == (1 << numCities) - 1) { 
        cout << " - 1";
        return; 
    } 
 
    int nextCity; 
    int minCost = INT_MAX; 
 
    for (int city = 0; city < numCities; city++) { 
        if ((visitedMask & (1 << city)) == 0) { 
            int cost = distanceMatrix[currentCity][city] +  
                       dpTable[city][visitedMask | (1 << city)]; 
            if (cost < minCost) { 
                minCost = cost; 
                nextCity = city;
            } 
        } 
    } 
    printPath(nextCity, visitedMask | (1 << nextCity)); 
} 
 
int main() { 
    cout << "No of cities: "; 
    cin >> numCities; 
 
    distanceMatrix = new int*[numCities]; 
    dpTable = new int*[numCities]; 
    for (int i = 0; i < numCities; i++) { 
        distanceMatrix[i] = new int[numCities]; 
        dpTable[i] = new int[1 << numCities];
    } 
 
    cout << "Distance Marix:\n"; 
    for (int i = 0; i < numCities; i++) { 
        for (int j = 0; j < numCities; j++) { 
            cin >> distanceMatrix[i][j];
        } 
    } 
 
    for (int i = 0; i < numCities; i++) {
    	for (int j = 0; j < (1 << numCities); j++) {
    		dpTable[i][j] = -1; 
		}  
	}
    int minCost = findMinCost(0, 1);
 
	cout << "\nMinimum cost: " << minCost << endl; 
	cout << "Path: "; 
	printPath(0, 1); 
	return 0; 
}
