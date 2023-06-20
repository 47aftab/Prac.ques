
// write a c++ code to check a graph is complete. represent the graph using adjacency list
#include <iostream>
#include <vector>
using namespace std;


bool isComplete(vector<vector<int>> adjList, int n){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && adjList[i][j] == 0){
                return false;
            }
        }
    }
    
    return true;
}

int main(){
    int n = 4;
    vector<vector<int>> adjList(n, vector<int>(n, 0));

    adjList[0][1] = 1;
    adjList[0][2] = 1;
    adjList[0][3] = 1;
    adjList[1][2] = 1;
    adjList[1][3] = 1;
    adjList[2][3] = 1;

    if (isComplete(adjList, n)){
        cout << "The graph is complete." << endl;
        }
    else
    {
        cout << "The graph is not complete." << endl;
    }
    return 0;
}


