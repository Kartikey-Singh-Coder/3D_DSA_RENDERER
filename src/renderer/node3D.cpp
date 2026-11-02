#include <renderer/node3D.hpp>

Node3D::Node3D(int value,Vector3 position): value(value) , position(position), radius(0.5f),color(BLUE){}

void Node3D::Render() const {
    DrawSphere(position, radius,color);
}

void Node3D::SetColor(Color color) {
    this->color = color;
}

void Node3D::SetPosition(const Vector3 position) {
    this->position = position;
}

int Node3D::GetValue() const {
    return value;
}

Vector3 Node3D::GetPosition() const {
    return position;
}

