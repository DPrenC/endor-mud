/****************************************************************************
Fichero: pasadizo11.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("suroeste", "./pasadizo10");
    AddExit("noroeste", "./pasadizo12");
}


