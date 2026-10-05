#include <raylib.h>

#include <render.h>

void renderer::doMainDrawLoop(Camera3D cam) {
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(cam);
            for( auto& fn : drawTasks3D ) { 
                fn();
            }
        EndMode3D();

        for( auto& fn : drawTasks2D ) {
            fn();
        }
        EndDrawing();
    }

    unloadAllModels();
}

void renderer::generateMeshes() {
    meshes.resize(renderer::meshNames::COUNT);
    meshes.at(renderer::meshNames::pointSphere) = GenMeshSphere(0.04f, 16, 16);
}