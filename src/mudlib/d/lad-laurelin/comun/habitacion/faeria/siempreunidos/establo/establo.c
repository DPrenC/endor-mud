/***
Fichero: establo.c
Autor: kastwey@simauria
Descripción: Establo de Siempreunidos.
Creación: 07/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("los establos de Siempreunidos");
    SetIntLong(W("Te encuentras en el interior del establo de Siempreunidos.\n"
    "Es una habitación más grande de lo que parecía desde fuera. Está dividida en dos zonas: La zona en la que estás, y otra habitación al este donde están los caballos.\n"));
    SetOficina(HAB_PUESTO("calles/calle_03"));
    SetIndoors(1);
    SetIntBright(30);
    AddExit("oeste", HAB_PUESTO("calles/calle_03"));
    AddExit("este", HAB_PUESTO("establo/estancia_caballos"));
    SetIntSmell("hmm. Huele a estiércol.\n");
    SetIntNoise("Escuchar sonidos de las patada de los animales hacia el este.\n");
}