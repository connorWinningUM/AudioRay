#include <core.h>
#include <raylib.h>

double distance(const Vector3& a, const Vector3& b) {
    return std::hypot(a.x - b.x, a.y - b.y, a.z - b.z);
}