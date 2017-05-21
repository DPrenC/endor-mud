/***
Fichero: estancia_caballos.c
autor: kastwey@simauria
Descripci�n: Habitafci�n donde est�n los caballos en Siempreunidos.
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("los establos de Siempreunidos");
    SetIntLong(W("Te encuentras en una estancia al este de la entrada del establo. El suelo est� lleno de paja, y gran cantidad de pesebres pueblan el lugar.\n"
    "Aqu� es donde los habitantes del pueblo, o los que quieran dejar sus monturas a buen resguardo pueden hacerlo con total confianza en que ser�n bien cuidadas.\n"));
    SetOficina(HAB_PUESTO("establo/establo"));
    SetIndoors(1);
    SetIntBright(25);
    AddItem(PNJ_PUESTO("caballo"), REFRESH_HOME, 1+random(3));
    AddDetail(({"pesebres", "pesebre"}), "Son unos altos pesebres donde se almacena la comida para que coman los animales.\n");
    SetIntNoise("Escuchas el relincho de los caballos.\n");
    SetIntSmell("Huele a esti�rcol.\n");
    AddExit("oeste", HAB_PUESTO("establo/establo"));
}