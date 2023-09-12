#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "interpolation.h"

int main(int argc, char **argv) {
  path_t path;
  int n;

  if (argc != 2) {
    printf("Usage: %s xe (point to aprox.)\n", argv[0]);
    exit(1);
  }

  int xe = strtod(argv[1], NULL);

  scanf("%d", &n);
  path.points = malloc(n * sizeof(point_t));
  path.num_points = n;
  
  readPoints(&path);

  double t = timestamp();
  double y = newtonInterpolation(path, xe);
  t = timestamp() - t;
  printf("Aproximation: %f @ %f\n", y, t);

  free(path.points);
  return 0;
}
