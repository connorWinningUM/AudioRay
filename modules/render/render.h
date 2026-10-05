#pragma once
#include <raylib.h>
#include <vector>
#include <functional>

namespace renderer {
    std::vector<std::function<void()>> drawTasks2D;
    std::vector<std::function<void()>> drawTasks3D;
    std::vector<Mesh> meshes;


    inline Camera3D getDefaultCam();

    void doMainDrawLoop(const Camera3D cam);

    enum meshNames {
        pointSphere=0,
    };
    void generateMeshes();
}

namespace drawTasks {
    void drawRayScene(const std::vector<audioRayLib::packet>& packets, const Model& pointSphere);
}