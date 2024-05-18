#include <iostream>
#include <queue>
#include <stack>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

// BFS function
void BFS(const IGraph& graph, int startVertex) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        for (int nextVertex : graph.GetNextVertices(vertex)) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                queue.push(nextVertex);
            }
        }
    }
    std::cout << std::endl;
}

// DFS function
void DFS(const IGraph& graph, int startVertex) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::stack<int> stack;

    stack.push(startVertex);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            std::cout << vertex << " ";
            visited[vertex] = true;
        }

        for (int nextVertex : graph.GetNextVertices(vertex)) {
            if (!visited[nextVertex]) {
                stack.push(nextVertex);
            }
        }
    }
    std::cout << std::endl;
}

int main() {
   
    ListGraph listGraph(5);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(3, 4);

    // Copy ListGraph to MatrixGraph
    MatrixGraph matrixGraph(listGraph);

    // Copy ListGraph to SetGraph
    SetGraph setGraph(listGraph);

    // Copy ListGraph to ArcGraph
    ArcGraph arcGraph(listGraph);

    // Verify the number of vertices
    std::cout << "Vertices Count: " << matrixGraph.VerticesCount() << std::endl;

    // Perform BFS and DFS on each graph
    std::cout << "BFS on MatrixGraph: ";
    BFS(matrixGraph, 0);

    std::cout << "DFS on MatrixGraph: ";
    DFS(matrixGraph, 0);

    std::cout << "BFS on SetGraph: ";
    BFS(setGraph, 0);

    std::cout << "DFS on SetGraph: ";
    DFS(setGraph, 0);

    std::cout << "BFS on ArcGraph: ";
    BFS(arcGraph, 0);

    std::cout << "DFS on ArcGraph: ";
    DFS(arcGraph, 0);

    return 0;
}
