/****************************************************************************
Fichero: pasadizo24.c
Autor: Ratwor
Fecha: 13/01/2008
Descripci�n: Unos pasadizos subterr�neos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("oeste", "./pasadizo23");
    AddExit("sudeste", "./pasadizo25");
    AddExit("suroeste", "./pasadizo39");
}


