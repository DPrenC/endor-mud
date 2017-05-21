/****************************************************************************
Fichero: pasadizo00.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("noroeste", "./pasadizo01");
    AddExit("este", "./pasadizo16");
    AddExit("sur", "./pasadizo68");
    AddExit("suroeste", "./entrada");
}


