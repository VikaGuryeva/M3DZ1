#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int verticesCount)
    : adjacencyMatrix(verticesCount, std::vector<bool>(verticesCount, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph)
    : MatrixGraph(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int to = 0; to < adjacencyMatrix[vertex].size(); ++to) {
        if (adjacencyMatrix[vertex][to]) {
            result.push_back(to);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < adjacencyMatrix.size(); ++from) {
        if (adjacencyMatrix[from][vertex]) {
            result.push_back(from);
        }
    }
    return result;
}
