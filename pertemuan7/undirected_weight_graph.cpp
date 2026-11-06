#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int banyakTitik) {
            this->numberVertex = banyakTitik;
            adjMatrix.resize(banyakTitik, vector<int>(banyakTitik, 0));
        }

    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        } else {
            cout << "Indeks tidak valid." << endl;
        };
    }

    void printAdjMatrix() {
        for (int i = 0; i < numberVertex; i++) {
            for (int j = 0; j < numberVertex; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        };
    }
};

int main(){
    system("cls");
    Graph graph(5);

    graph.addEdge(0,1,5);
    graph.addEdge(0,2,3);
    graph.addEdge(1,3,4);
    graph.addEdge(1,4,7);
    graph.addEdge(2,3,2);
    graph.addEdge(3,4,8);
    graph.printAdjMatrix();
}
