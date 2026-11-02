#include "renderer/renderer3D.hpp"
#include <vector>
Renderer3D::Renderer3D(const std::vector<Node3D> &Nodes,const std::vector<Edge3D> &Edges) : Nodes(Nodes), Edges(Edges) {}

void Renderer3D::AddNode(const Node3D& node) {
    this->Nodes.push_back(node);
}

void Renderer3D::AddEdge(const Edge3D& edge) {
    this->Edges.push_back(edge);
}

void Renderer3D::Render() const {
    for (const auto &node : this->Nodes) {
        node.Render();
    }
    for (const auto &edge : this->Edges) {
        edge.Render();
    }
}