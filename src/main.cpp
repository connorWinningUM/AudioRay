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
#define RESOLUTION 100

void settupTasks() {
    Vector3 src = {0, 0, 0};

    // must create the models in memory before doing the draw tasks
    renderer::generateMeshes();

    Model* pointSphere = renderer::loadTrackedModelFromMesh(renderer::meshes[renderer::meshNames::pointSphere]);
    std::vector<audioRayLib::packet> packets = audioRayLib::getEqualDistributedPackets(RESOLUTION, src, 1, 1000);

    // settup the tasks
    renderer::drawTasks3D.push_back([p = std::move(packets), pointSphere]() mutable {
        drawTasks::drawRayScene(std::move(p), *pointSphere);
    });
}

int main() {
    // do this before interacting with anything in raylib
    InitWindow(800, 450, "Ray Audio Engine");
    
    const std::vector<geometry::quad> roomGeometry = {
        { {100, 100, 100}, {100, 100, -100}, {100, -100, 100}, {100, -100, -100} },
        { {-100, 100, 100}, {-100, 100, -100}, {-100, -100, 100}, {-100, -100, -100} },
        { {100, 100, 100}, {100, 100, -100}, {-100, 100, 100}, {-100, 100, -100} },
        { {100, -100, 100}, {100, -100, -100}, {-100, -100, 100}, {-100, -100, -100} },
        { {100, 100, 100}, {100, -100, 100}, {-100, 100, 100}, {-100, -100, 100} },
        { {100, 100, -100}, {100, -100, -100}, {-100, 100, -100}, {-100, -100, -100} },
    };

    settupTasks();

    // start the rendering process
    Camera3D camera = renderer::getDefaultCam();
    renderer::doMainDrawLoop(camera);
}