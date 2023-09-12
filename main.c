#include <stdlib.h>
#include "interpolation.h"

int main(void) {
  path_t path;
  int n;
  scanf("%d", &n);
  path.points = malloc(n * sizeof(point_t));
  path.num_points = n;
  
  readPoints(&path);
  printPoints(&path);

  free(path.points);
  return 0;
}
