#include "interpolation.h"

void readPoints(path_t *path) {
    int i;
    int n = path->num_points;
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &path->points[i].x, &path->points[i].y);
    }
}

void printPoints(path_t *path) {
    int i;
    int n = path->num_points;
    for (i = 0; i < n; i++) {
        printf("%lf %lf\n", path->points[i].x, path->points[i].y);
    }
}