/****************************************************************************
Fichero: zona_servidumbre3.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: Unas escaleras que bajan a la bodega del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("la escalera a la bodega");
    SetIntLong(
    "Te encuentras ante unas escaleras mal iluminadas que sirven de antesala a "
    "la gran bodega del castillo.\n  Del este proviene un agradable tufillo a "
    "comida recién preparada.\n");
    SetIntBright(20);

    AddExit("este","./cocina" );
    AddExit("abajo","./bodega");
    SetIntSmell("Huele a buena comida.\n");

}