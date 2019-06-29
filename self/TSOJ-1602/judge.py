from random import randint
from os import system

M = int('9'*200)
# M=100


def n():
    a = randint(0, M)
    s = randint(0, 1)
    return -a if s else a


T = 100

with open("in", "w") as stdin, open("std", "w") as std:
    stdin.write(str(T)+'\n')
    for _ in range(T):
        a = n()
        b = n()
        stdin.write(str(a)+'\n')
        stdin.write(str(b)+'\n')
        c = a & b
        std.write(str(c)+'\n')

bin_path = "./TSOJ-1602.nosubmission"
system(f"carapace {bin_path} --input-path in --output-path out")
# system(f"{bin_path} < in > out")

if system("diff out std"):
    print("WA")
else:
    print("AC")
