/****************************************************************************
Fichero: pasadizo16.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("oeste", "./pasadizo00");
    AddExit("nordeste", "./pasadizo17");
}


