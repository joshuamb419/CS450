#ifndef TRACK_LOADER
#define    TRACK_LOADER

#include <vector>

/*
* trackWidth: width of the track in units, provided by file
* curbWidth: width of each curb in units, provided by file
* speed: roughly units/sec if points are spread evenly, provided by file
* carCount: number of cars to place onto the track, provided by file
* granularity: step size for Catmull-Rom spline generation for smoothing between points, provided by file
* trackPoints: vector of center points of the track, read in from file
* trackCenter: average position of all points in track, calculated when file is read in
* trackLength: distance covered by track, calculated using splined points, calculated during list creation
* minDistanceToCenter: the minimum distance from any point to the center of the track, calculated during curb creation
*
* .track Files are fomatted as follows, tracks should be defined in a clockwise manner
* newlines indicate a newline in the file
*
* <speed>:<curbWidth>:<carCount>:<trackWidth>:<granularity>
* <center_point_x_1>:<center_point_y_1>
* <center_point_x_2>:<center_point_y_2>
* <center_point_x_3>:<center_point_y_3>
*   .
*   .
*   .
* <center_point_x_n>:<center_point_y_n>
*/

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
        double minDistanceToCenter = 0.0;
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