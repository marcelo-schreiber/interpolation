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

double newtonInterpolation(path_t path, double xe) {
    int i, j;
    int n = path.num_points;
    double sum;
    double y = 0;
    double *divided_diff = (double *) malloc(n * sizeof(double));
    double *divisor = (double *) malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        divided_diff[i] = path.points[i].y;
        divisor[i] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            /* Divided difference: f[x0, x1, ..., xn] = (f[x1, ..., xn] - f[x0, ..., xn-1]) / (xn - x0) */
            divided_diff[j] = (divided_diff[j] - divided_diff[j - 1]) / (path.points[j].x - path.points[j - i].x);
        }
    }

    for (i = 0; i < n; i++) {
        sum = divided_diff[i];
        for (j = 0; j < i; j++) {
            /* Newton interpolation polynomial: Pn(x) = f[x0] + f[x0, x1](x - x0) + f[x0, x1, x2](x - x0)(x - x1) + ... + f[x0, x1, ..., xn](x - x0)(x - x1)...(x - xn-1) */
            sum *= (xe - path.points[j].x);
        }
        y += sum;
    }

    free(divided_diff);
    free(divisor);
    return y;
}

void interpolatePath(path_t *path, int method) {
    int i;
    int n = path->num_points;
    for (i = 0; i < n; i++) {
        /* Interpolate path */
        if (method == 0) {
            path->points[i].y = lagrangeInterpolation(*path, path->points[i].x);
        } else if (method == 1) {
            path->points[i].y = newtonInterpolation(*path, path->points[i].x);
        }
    }    
}