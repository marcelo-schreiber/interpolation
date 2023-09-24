#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <likwid.h>
#include "interpolation.h"

int main(int argc, char **argv)
{
  path_t path;
  int n;

  if (argc != 2)
  {
    printf("Usage: %s xe (point to aprox.)\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int xe = strtod(argv[1], NULL);

  int res = scanf("%d", &n);

  if (res != 1)
  {
    fprintf(stderr, "Error: n inválido\n");
    exit(EXIT_FAILURE);
  }
  path.points = malloc(n * sizeof(point_t));
  path.num_points = n;

  if (readPoints(&path, xe) != 1)
  {
    fprintf(stderr, "Error: xe inválido\n");
    exit(EXIT_FAILURE);
  }

  LIKWID_MARKER_INIT;

  double tNewton = timestamp();

  LIKWID_MARKER_START("newton");
  double yNewton = newtonInterpolation(path, xe);
  LIKWID_MARKER_STOP("newton");

  tNewton = timestamp() - tNewton;

  double tLagrange = timestamp();

  LIKWID_MARKER_START("lagrange");
  double yLagrange = lagrangeInterpolation(path, xe);
  LIKWID_MARKER_STOP("lagrange");

  tLagrange = timestamp() - tLagrange;

  printf("%lf\n%lf\n%lf\n%lf\n", yLagrange, yNewton, tLagrange, tNewton);

  LIKWID_MARKER_CLOSE;

  free(path.points);
  return EXIT_SUCCESS;
}
