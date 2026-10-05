#pragma once
#include <raylib.h>
#include <vector>
#include <functional>

#include <core.h>

namespace renderer {
    inline std::vector<std::function<void()>> drawTasks2D;
    inline std::vector<std::function<void()>> drawTasks3D;
    inline std::vector<Mesh> meshes;
    inline std::vector<Model> loadedModels;

    inline Model* loadTrackedModel(const char* fileName) {
        Model m = LoadModel(fileName);
        loadedModels.push_back(m);
        return &loadedModels.back();
    }
    inline Model* loadTrackedModelFromMesh(Mesh mesh) {
        Model m = LoadModelFromMesh(mesh);
        loadedModels.push_back(m);
        return &loadedModels.back();
    }
    inline void unloadAllModels() {
        for (Model& model : loadedModels) {
            UnloadModel(model);
        }
        loadedModels.clear();
    }

    inline Camera3D getDefaultCam() {
        return Camera3D {
            .position={ 5.0f, 5.0f, 0.0f },
            .target={ 0.0f, 0.0f, 0.0f },
            .up={ 0.0f, 1.0f, 0.0f },
            .fovy=45.0f,
            .projection=CAMERA_PERSPECTIVE,
        };
    }

    void doMainDrawLoop(const Camera3D cam);

    enum meshNames {
        pointSphere=0,
        COUNT,
    };
    void generateMeshes();
}

namespace drawTasks {
    void drawRayScene(const std::vector<audioRayLib::packet>& packets, const Model& pointSphere);
}