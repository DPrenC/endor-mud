/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Guardia Base Enalel
 *****************************************************************************/

#include "./path.h"

inherit ENALPNJ"base";
inherit GUARD;

create(){
    "*"::create();

    AddId(({"guardia", "guardiaEnalel", "guardia de enalel"}));
    SetCitizenship("enalel");
}
