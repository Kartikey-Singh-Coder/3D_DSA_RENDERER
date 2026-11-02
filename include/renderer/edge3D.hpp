#pragma once
#include "raylib.h"
class Edge3D {
    private:
    Vector3 positionStart;
    Vector3 positionEnd;
    int weight;
    Color color;
    public:
    Edge3D(Vector3 positionStart, Vector3 positionEnd, int weight);
    void Render() const;

    void SetEndPoints(Vector3 positionStart,Vector3 positionEnd);
    void SetColor(Color color);

    [[nodiscard]] int GetWeight() const ;
};