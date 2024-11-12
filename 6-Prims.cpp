#include <iostream>
using namespace std;

int minKey(int key[], bool included[], int nodes) {
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < nodes; v++) {
        if (!included[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prims (int graph[100][100], int nodes) {
	
	int parent[nodes];
	int key[nodes];
	bool included[nodes];
	
	for (int i = 0; i < nodes; i++) {
		key[i] = INT_MAX;
		included[i] = false;
	}
	
	key[0] = 0;
	parent[0] = -1;
	
	for (int i = 0; i < nodes - 1; i++) {
		int u = minKey(key, included, nodes);
		included[u] = true;
		
		for (int v = 0; v < nodes; v++) {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
	}
	
	cout << "Edge\tWeight\n";
	int total = 0;
    for (int i = 1; i < nodes; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }
    
    cout << "Total weight: " << total << endl;
}

int main () {
	
	int nodes;
	cout << "Enter the number of nodes (Max Limit 100): ";
	cin >> nodes;
	int graph[100][100];
	
	cout << "Enter the adjacency matrix for the graph (0 for no edge): \n";
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			cin >> graph[i][j];
		}
	}
	
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			graph[j][i] = graph[i][j];
		}
	}
	
	prims(graph, nodes);
	return 0;
	
}
