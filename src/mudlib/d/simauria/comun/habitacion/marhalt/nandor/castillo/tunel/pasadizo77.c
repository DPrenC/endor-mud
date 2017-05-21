/****************************************************************************
Fichero: pasadizo77.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("noroeste", "./pasadizo76");
    AddExit("sur", "./pasadizo78");
}


