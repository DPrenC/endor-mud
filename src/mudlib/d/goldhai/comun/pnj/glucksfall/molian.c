/****************************************************************************
Fichero: Molian.c
Autor: Kastwey
Fecha: 08/03/2006
Descripción: Molian, el banquero de Glucksfall
****************************************************************************/


#include "path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("Molian","humano",([GC_LUCHADOR:20]), GENDER_MALE);
    SetShort("Molian, el banquero");
    SetLong("Molian es el banquero de esta peligrosa ciudad. Es un personaje "
            "mal encarado, con una gran cicatriz que le cruza la frente de lado "
            "a lado. Atiende a los clientes tras una reja de gruesos barrotes, para "
            "evitar posibles ataques.\n");

    AddId("banquero");
    InitChats(4, ({"Molian te dice: Si tienes algo de dinero te recomiendo que lo "
                   "ingreses cuanto antes.\n",
                   "Molian refunfuña: Cada vez viene menos gente... Al final "
                   "acabaré cerrando la oficina.\n"}));

}


