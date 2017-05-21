/****************************************************************************
Fichero: pasillo2.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En las mazmorras del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("mazmorras/mazmorras_base");

create(){
    ::create();
    SetIntLong("Est�s en un angosto pasadizo abovedado, excavado bajo los cimientos de "
    "la muralla del castillo. En las paredes, algunos soportes de antorchas cuelgan "
    "medio sueltos. Al sureste atisbas una escalera ascendente y al noroeste contin�a el pasillo.\n");
    AddExit("noroeste", "./pasillo3");
    AddExit("sudeste", "./pasillo1");
}

