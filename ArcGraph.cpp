#pragma once
#include "ArcGraph.h"

ArcGraph::ArcGraph(int verticesCount)
    : verticesCount(verticesCount) {}

ArcGraph::ArcGraph(const IGraph& graph)
    : ArcGraph(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    arcs.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (const auto& arc : arcs) {
        if (arc.first == vertex) {
            result.push_back(arc.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (const auto& arc : arcs) {
        if (arc.second == vertex) {
            result.push_back(arc.first);
        }
    }
    return result;
}
