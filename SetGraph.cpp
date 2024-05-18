#include "SetGraph.h"

SetGraph::SetGraph(int verticesCount)
    : adjacencySets(verticesCount) {}

SetGraph::SetGraph(const IGraph& graph)
    : SetGraph(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacencySets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < adjacencySets.size(); ++from) {
        if (adjacencySets[from].find(vertex) != adjacencySets[from].end()) {
            result.push_back(from);
        }
    }
    return result;
}

