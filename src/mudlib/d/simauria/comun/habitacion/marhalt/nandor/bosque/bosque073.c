/****************************************************************************
Fichero: bosque073.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque066");
    AddExit("oeste","./bosque072");
    AddExit("este", "./bosque074");
    AddExit("suroeste", "./bosque077");

}


