#!/bin/python
from os import system

system("make")

xe = float(input("Digite o valor de x: "))
# xe = float(input(""))

system(f"likwid-perfctr -C 3 -g FLOPS_DP -m ./interpola {xe} < pontos.in > resultado.out")

print("") # Pula linha
system("grep -e \"MFLOP/s\" -e \"newton\" -e \"lagrange\" resultado.out")
print("") # Pula linha

system("make purge")
