from os import system

binary = "./1569.5"

for i in range(1, 11):
    system(f"cp input{i}.txt in")
    system(f"cp output{i}.txt std")
    system(f"{binary} < in > out")
    if system("diff out std") != 0:
        print(i)
        break
    with open("out") as f:
        print(i, f.read())

print("std:")

for i in range(1, 11):
    with open(f"output{i}.txt") as f:
        print(i, f.read())
