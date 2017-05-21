/****************************************************************************
Fichero: pasadizo23.c
Autor: Ratwor
Fecha: 13/01/2008
Descripción: Unos pasadizos subterráneos en el castillo de Nandor.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("tunel/pasadizo_base");
create(){
    ::create();

    AddExit("oeste", "./pasadizo22");
    AddExit("este", "./pasadizo24");
    AddExit("noroeste", "./pasadizo38");
}


