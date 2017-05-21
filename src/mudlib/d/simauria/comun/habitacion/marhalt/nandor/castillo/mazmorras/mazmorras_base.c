/****************************************************************************
Fichero: mazmorras_base.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: el archivo base de las mazmorras del castillo, solo para el pasillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("el oscuro pasillo de las mazmorras");
    SetLocate("el castillo de Nandor");
    SetIntBright(10);
    SetIntSmell("Huele intensamente a humedad.\n");
    SetIntNoise(
    "Extrañamente no se oye nada. El lugar esta tan silencioso como una tumba...\n");
    AddDetail("soportes", "Viejos soportes de hierro oxidados y en ocasiones medio "
    "desprendidos del muro que los sustenta.\n");
    AddDetail(({"paredes", "muros", "pared", "muro"}),
    "No tienen nada especial.\n");
    if(d3()==1)
        AddItem(PNJCASTILLO("rata"), REFRESH_DESTRUCT, d2());
}

