#!/bin/python
from os import system

system("make")

xe = float(input("Digite o valor de x: "))
# xe = float(input(""))

system(f"likwid-perfctr -C 3 -g FLOPS_DP -m ./interpola {xe} < pontos.in > resultado.out")
system("grep \"MFLOP/s\" resultado.out")
system("make purge")
