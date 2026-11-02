#include "renderer/edge3D.hpp"

Edge3D::Edge3D(const Vector3 positionStart,const Vector3 positionEnd,const int weight): positionStart(positionStart),positionEnd(positionEnd),weight(weight),color(WHITE) {}

void Edge3D::SetColor(Color color) {
    this->color = color;
}

void Edge3D::SetEndPoints(const Vector3 positionStart,const Vector3 positionEnd) {
    this->positionStart = positionStart;
    this->positionEnd = positionEnd;
}

void Edge3D::Render() const {
    DrawLine3D(positionStart,positionEnd,color);
}

int Edge3D::GetWeight() const {
    return weight;
}
