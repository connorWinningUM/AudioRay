#include <render.h>
#include <core.h>

void drawTasks::drawRayScene(const std::vector<audioRayLib::packet>& packets, const Model& pointSphere) {
    for( auto& p : packets ) {
        DrawModel(pointSphere, p.ray.direction, 1, RED);
    }
    DrawGrid(10, 1.0f);
}