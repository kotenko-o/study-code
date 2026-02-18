#include <stdio.h>

#define PATH_FILE_1 "sensor1.txt"
#define PATH_FILE_2 "sensor2.txt"

#define THRESHOLD_SENSOR_1 0.8
#define THRESHOLD_SENSOR_2 0.7

typedef struct {
    float time;
    double probability;
} SensorData;

typedef struct {
    int id;
    double threshold;
    SensorData data[3000];
    int object_detection[3000];
} Sensor;

int main() {

    char buffer_line[256];

    Sensor sensor_1;
    Sensor sensor_2;

    sensor_1.id = 1;
    sensor_1.threshold = THRESHOLD_SENSOR_1;

    sensor_2.id = 2;
    sensor_2.threshold = THRESHOLD_SENSOR_2;

    FILE* file1 = fopen(PATH_FILE_1, "r");
    FILE* file2 = fopen(PATH_FILE_2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("An error occured, while reading the files.");
        return 1;
    }



    return 0;
}