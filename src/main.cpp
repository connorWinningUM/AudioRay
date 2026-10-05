#include <print>
#include <vector>
#include <raylib.h>
#include <numbers>
#include <cmath>
#include <limits>
#include <functional>

#include <core.h>
#include <render.h>

#define amplitude_threshold 0.001
#define RESOLUTION 64

int main() {

    InitWindow(800, 450, "raylib [core] draw ray example");
    
    std::vector<geometry::quad> roomGeometry = {
        { {100, 100, 100}, {100, 100, -100}, {100, -100, 100}, {100, -100, -100} },
        { {-100, 100, 100}, {-100, 100, -100}, {-100, -100, 100}, {-100, -100, -100} },
        { {100, 100, 100}, {100, 100, -100}, {-100, 100, 100}, {-100, 100, -100} },
        { {100, -100, 100}, {100, -100, -100}, {-100, -100, 100}, {-100, -100, -100} },
        { {100, 100, 100}, {100, -100, 100}, {-100, 100, 100}, {-100, -100, 100} },
        { {100, 100, -100}, {100, -100, -100}, {-100, 100, -100}, {-100, -100, -100} },
    };

    Vector3 vmic = {60, 10, 0};
    Vector3 src = {0, 0, 0};

    std::vector<audioRayLib::packet> packets = audioRayLib::getEqualDistributedPackets(RESOLUTION, src, 1, 1000);

    Camera3D camera = renderer::getDefaultCam();

    // create meshes/models in memory before drawing
    renderer::generateMeshes();
    Model pointSphere = LoadModelFromMesh(renderer::meshes[renderer::meshNames::pointSphere]);

    renderer::drawTasks3D.push_back(std::bind(drawTasks::drawRayScene, packets, pointSphere));
    renderer::doMainDrawLoop(camera);

    UnloadModel(pointSphere);
}