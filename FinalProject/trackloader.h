#ifndef TRACK_LOADER
#define    TRACK_LOADER

#include <vector>

class Track {
    private:
        float speed;
        int carCount;
        float curbWidth;
        float trackWidth;
        float granularity;
        float trackCenter[2] = {0., 0.};
        std::vector<float*> trackPoints;
    public:
        double trackLength = 0.0;
        Track(char* file);

        int getCarCount();
        float* getCarPosition(int carNumber);
        std::vector<float*>* getTrackPoints();
        float getTrackWidth();
        float getGranularity();
        float getCurbWidth();
        float* getTrackCenter();
        float getCarSpeed();
};

#endif