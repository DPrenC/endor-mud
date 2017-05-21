/****************************************************************************
Fichero: patio18.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <properties.h>
inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+"Justo al oeste, unos amplios escalones acceden al port�n "
    "de dos batientes que da entrada a la torre del homenaje.\n");
    AddDetail("escalones", "Tres amplios escalones de piedra que ascienden hasta la "
    "puerta de la torre del homenaje.\n");
    AddDetail(({"escudo", "escudo de port�n", "escudo de porton"}), "Es el escudo de "
    "los Desh-Blain grabado en bronce.\n Representa una flor de lis desplegada "
    "sobre la empu�adura de un mandoble.\n");
 
    AddExit("oeste", CASTILLO("planta1/vestibulo"));
    AddExit("este",  "./patio19");
    AddExit("norte", "./patio16");
    AddExit("nordeste", "./patio17");
    AddExit("sur", "./patio20");
    AddExit("sudeste", "./patio21");
    AddDoor("oeste", "un gran port�n", "Un gran port�n de madera aherrada en forma de "
    "arco, sobre cuyos batientes aparece el escudo de los Dhes-Bl�in.\n",
    ({"port�n", "puerta", "gran port�n",
    "gran porton", "porton"}), GENDER_MALE,
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_porton"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_porton")]));
}


