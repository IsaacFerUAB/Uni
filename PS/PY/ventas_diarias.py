#!/bin/python3

montos = []
monto=0
while monto != "-1":
    monto=input("Introduece los montos: ")
    montos.append(str(monto) + '\n')

f=open("ventas.txt","w")
for linea in montos:
    f.write(linea)
f.close()