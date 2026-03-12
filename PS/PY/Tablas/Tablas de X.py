#!/bin/python


T=input("Fins a quina taula vols fer (0 no inclosa), Inclou la eleccio: ")

taules=[]
for i in range(int(T) + 1):
    if i != 0:
        taules.append(i)
print(taules)

#taula-del-X
for i in taules:
    taula = "taula-del- " + str(i)
    f=open(taula,"w")
    for j in range(1, 11):
        line = str(i) + " * " + str(j) + " = "
        x = int(i)*int(j)
        f.write(str(line) + str(x) + "\n")
        
    f.close()
