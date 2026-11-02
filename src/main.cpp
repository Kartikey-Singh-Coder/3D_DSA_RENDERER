
#include "raylib.h"
#include "renderer/node3D.hpp"
#include "renderer/renderer3D.hpp"

int main() {
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE);

    InitWindow(1280, 800, "DataVerse");
    DisableCursor();

    SetTargetFPS(60);

    Camera3D camera = {0};

    camera.position = {8, 8, 8};
    camera.target = {0, 1, 0};
    camera.up = {0, 1, 0};
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    Node3D firstNode(10, {0, 1, 0});
    Node3D secondNode(20, {3, 1, 0});
    Node3D thirdNode(30, {1.5f, 3, 0});

    thirdNode.SetColor(RED);

    Edge3D firstEdge(firstNode.GetPosition(), secondNode.GetPosition(), 5);
    Edge3D secondEdge(secondNode.GetPosition(), thirdNode.GetPosition(), 8);
    Edge3D thirdEdge(thirdNode.GetPosition(), firstNode.GetPosition(), 3);

    Renderer3D renderer(
    {firstNode, secondNode, thirdNode},
    {firstEdge, secondEdge, thirdEdge}
    );

    secondNode.SetColor(GOLD);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();
        ClearBackground({15, 18, 28, 255});

        BeginMode3D(camera);

        DrawGrid(20, 1.0f);

        renderer.Render();

        EndMode3D();

        DrawText("DATAVERSE", 30, 25, 30, RAYWHITE);
        DrawFPS(30, 70);

        EndDrawing();
    }

    EnableCursor();
    CloseWindow();

    return 0;
}
