/****************************************************************************
Fichero: pasadizo45.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("sudeste", "./pasadizo46");
    AddExit("suroeste", "./pasadizo44");
}


