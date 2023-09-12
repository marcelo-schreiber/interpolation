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

double lagrangeInterpolation(path_t path, double xe) {
    int i, j;
    int n = path.num_points;
    double sum;
    double y = 0;
    for (i = 0; i < n; i++) {
        sum = 1;
        for (j = 0; j < n; j++) {
            if (i != j) {
                /* Li(x) = (x - x0)/(xi - x0) * (x - x1)/(xi - x1) * ... * (x - xi-1)/(xi - xi-1) * (x - xi+1)/(xi - xi+1) * ... * (x - xn)/(xi - xn) */
                sum *= (xe - path.points[j].x) / (path.points[i].x - path.points[j].x);
            }
        }
        y += sum * path.points[i].y;
    }

    return y;
}

