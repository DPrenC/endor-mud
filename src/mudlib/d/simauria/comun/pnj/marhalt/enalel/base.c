/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ Base Enalel
 *****************************************************************************/

#include "./path.h"

inherit NPC;

create(){
    ::create();

    AddId(({"ciudadano", "pueblerino"}));
    SetCitizenship("enalel");

    if(d3()==1)
        AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":d3(),"plata":d6()])]));
}
