#pragma once
#include "ListGraph.h"

ListGraph::ListGraph(int verticesCount)
    : adjacencyLists(verticesCount) {}

ListGraph::ListGraph(const IGraph& graph)
    : ListGraph(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacencyLists.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int nextVertex : adjacencyLists[vertex]) {
        result.push_back(nextVertex);
    }
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < adjacencyLists.size(); ++from) {
        for (int to : adjacencyLists[from]) {
            if (to == vertex) {
                result.push_back(from);
            }
        }
    }
    return result;
}
