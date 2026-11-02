#pragma once

# include "raylib.h"
class Node3D {
    private:
        int value;
        Vector3 position;
        float radius;
        Color color;
    public:
    Node3D(int value,Vector3 position);
    void Render() const ;

    void SetPosition(Vector3 position);
    void SetColor(Color color);

    [[nodiscard]] int GetValue() const ;
    [[nodiscard]] Vector3 GetPosition() const;
};