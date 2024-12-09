#include "trackloader.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

Track::Track(char* filepath) {
    std::ifstream file(filepath);
    std::string line;
    char* token;

    std::getline(file, line);

    token = std::strtok(line.data(), ":");
    this->speed = std::stof(token);

    token = std::strtok(nullptr, ":");
    this->curbWidth = std::stof(token);

    token = std::strtok(nullptr, ":");
    this->carCount = std::stoi(token);

    token = std::strtok(nullptr, ":");
    this->trackWidth = std::stof(token);

    token = std::strtok(nullptr, ":");
    this->granularity = std::stof(token);

    // printf("Speed: %f, Curb Width: %f, Car Count: %d, Track Width: %f\n", speed, curbWidth, carCount, trackWidth);
    while(std::getline(file, line)) {
        token = strtok(line.data(), ",");
        float x = std::stof(token);

        token = strtok(nullptr, ",");
        float y = std::stof(token);

        // printf("%f, %f\n", x, y);
        float* trackPoint = (float *) malloc(2*sizeof(float));
        trackPoint[0] = x;
        trackPoint[1] = y;
        trackPoints.push_back(trackPoint);

        trackCenter[0] += x;
        trackCenter[1] += y;
    }

    trackCenter[0] /= trackPoints.size();
    trackCenter[1] /= trackPoints.size();
}

int Track::getCarCount() {
    return carCount;
}

float* Track::getCarPosition(int carNumber) {
    float position[2];

    position[0] = 0.0;
    position[1] = 0.0;

    return position;
}

std::vector<float*>* Track::getTrackPoints() {
    return &trackPoints;
}

float Track::getTrackWidth() {
    return trackWidth;
}

float Track::getCurbWidth() {
    return curbWidth;
}

float Track::getGranularity() {
    return granularity;
}

float* Track::getTrackCenter() {
    return trackCenter;
}

float Track::getCarSpeed() {
    return speed;
}