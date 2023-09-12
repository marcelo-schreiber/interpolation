#include <stdio.h> 
#include <stdlib.h>

typedef struct {
  double x;
  double y;
} point_t;

typedef struct {
  point_t *points;
  int num_points;
} path_t;


void printPoints(path_t *path);
void readPoints(path_t *path);
double lagrangeInterpolation(path_t path, double xe);
double newtonInterpolation(path_t path, double xe);