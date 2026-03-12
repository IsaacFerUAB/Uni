#!/bin/python

usuario=input("INTRODUCIR USUARIO: ")

f=open("PY/usuarios.txt")
llista=f.readlines()
f.close()

#NUEVO USUARIO
def newuser():
    userexists = True
    while userexists == True:
        newuser = input("Introduce el nombre de usuario")

        for i in range(len(llista)):
            camps = llista[i]
            camps = camps.strip()
            camps = camps.split(":")
            if camps[0] == newuser:
                userexists = True
                print("ERROR: El usuario ya existe'\n'")
            else: 
                userexists = False 
                break
    
    newpassw = input("Introduce la nueva contraseña: ")
    newline = []
    newline.append(newuser)
    newline.append(newpassw + '\n')
    newline = ":".join(newline)
    f=open("PY/usuarios.txt","a")
    f.write(newline)
    f.close()

#USER CHECK + ADMINCHECK
for i in range(len(llista)):
    camps = llista[i]
    camps = camps.strip()
    camps = camps.split(":")
    if camps[0] == usuario: 
        usercheck = True
        i = range(len(llista))
        passw = camps[1]
        if usuario == "admin":
            SUPERVISORMODE = True
        break
    else: 
        usercheck = False

#PASSWORD INPUT
counter = 3
if usercheck == True:
    while int(counter) != 0:
        contra=input("INTRODUCIR CONTRASEÑA: ")

        if passw == contra:
            print("- Bienvenido al sistema -")
            counter = 0
        else: 
            print("Contrasaeña incorrecta")
            print("Tienes " + str(counter) + " intento/s.")
            counter = counter-1
else:
    print(" - - USUARIO NO ENCONTRADO - - ")

#MODO ADMIN
SUPERVISORMODE = True
if SUPERVISORMODE == True:
    print("---- ADMIN MENU ----")
    print("  1.Añadir Usuarios")
    print("  2.Editar Usuarios")
    print("  3.Eliminar Usuarios")
    print("  4.Cambiar contraseña admin")
    print("  X.Cerrar Sesion")
    print("---- -------- ---- '\n'")
    opcion = input("Que quieres hacer: ")
    
    match opcion:
        case "1":
            newuser()
        case "2": print("FUNCION NO AÑADIDA")
        case "3": print("FUNCION NO AÑADIDA")
        case "4": print("FUNCION NO AÑADIDA")
        case "5": exit()
        case _: print("REINTENTAR")
