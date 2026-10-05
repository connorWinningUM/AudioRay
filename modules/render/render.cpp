#include <raylib.h>

#include <render.h>

inline Camera3D renderer::getDefaultCam() {
    return Camera3D {
        .position={ 5.0f, 5.0f, 0.0f },
        .target={ 0.0f, 0.0f, 0.0f },
        .up={ 0.0f, 1.0f, 0.0f },
        .fovy=45.0f,
        .projection=CAMERA_PERSPECTIVE,
    };
}

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
}

void renderer::generateMeshes() {
    meshes["pointSphere"] = GenMeshSphere(0.04f, 16, 16);
}