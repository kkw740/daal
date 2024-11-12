#include <iostream> 
#include <climits> 
using namespace std; 
 
int numCities;            
int distanceMatrix[20][20];
int bestPath[20];
int currentPath[20];
bool visited[20];      
int minCost = INT_MAX;  

int calculateCost(int path[], int numVisited) { 
    int cost = 0; 
    for (int i = 0; i < numVisited - 1; i++) { 
        cost += distanceMatrix[path[i]][path[i + 1]]; 
    } 
    cost += distanceMatrix[path[numVisited - 1]][path[0]];
    return cost; 
} 

void branchAndBound(int currentCity, int numVisited) { 
    if (numVisited == numCities) { 
        int cost = calculateCost(currentPath, numVisited); 
        if (cost < minCost) { 
            minCost = cost;
            for (int i = 0; i < numVisited; i++) { 
                bestPath[i] = currentPath[i]; 
            } 
        } 
        return; 
    } 

    for (int nextCity = 0; nextCity < numCities; nextCity++) { 
        if (!visited[nextCity]) {
            visited[nextCity] = true; 
            currentPath[numVisited] = nextCity;
            branchAndBound(nextCity, numVisited + 1); 
            visited[nextCity] = false;
        } 
    } 
} 
 
int main() { 
    cout << "Enter the number of cities: "; 
    cin >> numCities; 
    for (int i = 0; i < numCities; i++) { 
        for (int j = 0; j < numCities; j++) { 
            distanceMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        } 
    } 
    int edges; 
    cout << "No of edges: "; 
    cin >> edges; 
    cout << "Enter edges in the format (city1 city2 distance):\n"; 
    for (int i = 0; i < edges; i++) { 
        int city1, city2, distance; 
        cin >> city1 >> city2 >> distance; 
        distanceMatrix[city1 - 1][city2 - 1] = distance; 
        distanceMatrix[city2 - 1][city1 - 1] = distance;
    } 
    visited[0] = true; 
    currentPath[0] = 0;
    branchAndBound(0, 1);

    cout << "\nMinimum cost: " << minCost << endl; 
    cout << "Path: "; 
    for (int i = 0; i < numCities; i++) { 
        cout << bestPath[i] + 1;
        if (i < numCities - 1) cout << " - "; 
    } 
    cout << endl; 
 
    return 0; 
}
