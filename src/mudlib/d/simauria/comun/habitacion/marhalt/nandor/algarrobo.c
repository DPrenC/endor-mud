/****************************************************************************
Fichero: algarrobo.c
Autor: Ratwor
Fecha: 09/08/2007
Descripci�n: En lo alto del algarrobo de Nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit SIM_ROOM;

public string mirar_abajo(){
    object abajo = find_object(MARH("nandor/calle6"));
    if (!abajo)
    return "Se ve la calle solitaria.\n";
    write("Miras hacia abajo y ves que la calle est� algo apartada del n�cleo de "
    "la aldea que est� hacia el norte, por lo tanto se nota la tranquilidad.\n Hacia "
    "el sur ves la salida de la aldea, con un cruce a lo lejos.\n Una casucha al este "
    "y el algarrobo en el que est�s subido es lo �nico que destaca de la zona.\n"
    + abajo->Content());
    return "";
}

create(){
    ::create();
    SetLocate("aldea de nandor");
    SetIntShort("lo alto de un algarrobo");
    SetIntLong("Te encuentras en lo alto de un viejo algarrobo. Sus anchas ramas "
    "permiten el peso de unas pocas personas, aunque tampoco habr�a que excederlo "
    "demasiado.\n El ambiente de tranquilidad, sus frutos poblando las ramas, y el "
    "silencio que reina aqu� arriba invitan a la relajaci�n, pero sin olvidarse qe se "
    "est� suspendido sobre unas pocas ramas.\n");
    SetIndoors(0);
    SetIntNoise("Est� todo bastante silencioso.\n");
    SetIntSmell("Huele un poco a las algarrobas del �rbol.\n");
    AddDetail(({"arbol", "�rbol", "algarrobo"}), "Es un viejo �rbol de tronco rugoso "
        "y hojas de color verde. Aunque no parece que lo cuiden mucho, este �rbol se "
        "las arregla para continuar dando algarrobas.\n");
    AddDetail(({"algarroba", "algarrobas", "frutos", "fruto"}), "las algarrobas son "
        "vainas retorcidas de color verde amarronado con que muchas veces se alimentan "
        "los caballos que tiran de las diligencias que pasan por aqu�.\n");
    AddDetail(({"abajo", "calle"}), SF(mirar_abajo));

    SetMaxIntWeight(500000);
    AddExit("abajo", "./calle6");
    AddRoomCmd("coger", "cmd_coger");
}

public int cmd_coger(string str){
    if (!str) return 0;
    if (str=="algarrobas" || str=="algarroba" || str=="fruto" || str=="frutos"){
        write("Las algarrobas son para los caballos y los burros. Ni que pasaras "
        "hambre...\n");
        return 1;
    }
}
