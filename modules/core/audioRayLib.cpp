#include <cmath>
#include <raylib.h>
#include <numbers>
#include <vector>

#include <core.h>

double audioRayLib::getAmplitude(double dampingCoefficient, double originalAmplitudeSample, double distTraveled) {
    double a = originalAmplitudeSample / distTraveled;
    double b = std::exp(dampingCoefficient * originalAmplitudeSample);
    return a * b;
}

double audioRayLib::getPhaseShift(double frequency, double distTraveled, double propogationSpeed) {
    double numerator = two_pi * frequency * distTraveled;
    return numerator / propogationSpeed;
}

std::vector<audioRayLib::packet> audioRayLib::getEqualDistributedPackets(int resolution, Vector3 srcPosition, double amplitude, double frequency) {
    int numPackets = std::pow(resolution, 2);
    std::vector<packet> packets(numPackets);

    float distribution = two_pi / resolution;

    // do less than two_pi to prevent multiple packets with a ray in the same direction
    int i = 0;
    int overflowCount = 0;
    for( float zenith = 0.0; zenith < two_pi ; zenith += distribution) {
        for( float azimuth = 0.0; azimuth < two_pi ; azimuth += distribution) {
            Ray r {
                .position=srcPosition,
                .direction=polarToVector(zenith, azimuth),
            };
            if( i >= numPackets ) {
                overflowCount++;
                continue;
            }
            packets[i] = packet {
                .distTraveled = 0,
                .amplitude = amplitude,
                .frequency = frequency,
                .phase = 0,
                .ray = r,
            };
            i++;
        }
    }

    return packets;
}