/***
Fichero: establo.c
Autor: kastwey@simauria
Descripci�n: Establo de Siempreunidos.
Creaci�n: 07/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("los establos de Siempreunidos");
    SetIntLong(W("Te encuentras en el interior del establo de Siempreunidos.\n"
    "Es una habitaci�n m�s grande de lo que parec�a desde fuera. Est� dividida en dos zonas: La zona en la que est�s, y otra habitaci�n al este donde est�n los caballos.\n"));
    SetOficina(HAB_PUESTO("calles/calle_03"));
    SetIndoors(1);
    SetIntBright(30);
    AddExit("oeste", HAB_PUESTO("calles/calle_03"));
    AddExit("este", HAB_PUESTO("establo/estancia_caballos"));
    SetIntSmell("hmm. Huele a esti�rcol.\n");
    SetIntNoise("Escuchar sonidos de las patada de los animales hacia el este.\n");
}