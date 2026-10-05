#pragma once
#include <cmath>
#include <raylib.h>
#include <numbers>
#include <vector>

constexpr double two_pi = 2.0 * std::numbers::pi;

namespace audioRayLib {

    struct packet {
        double distTraveled;
        double amplitude;
        double frequency;
        double phase;
        
        Ray ray;
    };

    inline Vector3 polarToVector(float zenith, float azimuth) {
        return Vector3 {
            .x = std::sin(zenith) * std::cos(azimuth),
            .y = std::sin(zenith) * std::sin(azimuth),
            .z = std::cos(zenith),
        };
    }
    inline bool nyquistFilter(double freq, double sampleRate) { return freq >= sampleRate / 2; }

    double getAmplitude(double dampingCoefficient, double originalAmplitudeSample, double distTraveled);
    double getPhaseShift(double frequency, double distTraveled, double propogationSpeed);
    std::vector<packet> getEqualDistributedPackets(int resolution, Vector3 srcPosition, double amplitude, double frequency);

    void stepPacket(packet& p);
    void stepAllPackets(std::vector<packet>& packets);
}

namespace geometry {
    struct quad {
        Vector3 p1;
        Vector3 p2;
        Vector3 p3;
        Vector3 p4;
    };

    double distance(const Vector3& a, const Vector3& b);
}