#pragma once

#include "renderer/Node3D.hpp"
#include "renderer/Edge3D.hpp"
#include <vector>

class Renderer3D {
private:
    std::vector<Node3D> Nodes;
    std::vector<Edge3D> Edges;
public:
    Renderer3D(const std::vector<Node3D> &Nodes,const std::vector<Edge3D> &Edges);
    void AddNode(const Node3D& node);
    void AddEdge(const Edge3D& edge);

    void Render() const ;
};