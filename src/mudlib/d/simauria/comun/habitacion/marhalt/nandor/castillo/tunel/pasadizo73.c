/****************************************************************************
Fichero: pasadizo73.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("noroeste", "./pasadizo72");
    AddExit("sur", "./pasadizo74");
}


