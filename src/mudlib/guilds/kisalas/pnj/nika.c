/****************************************************************************
Fichero: nika.c
Autor: Riberales
Fecha: 15/02/2006
Descripción: La banquera del gremio kisalo.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

create()
{
    ::create();
    ::create();
    SetStandard("nika","medio-elfo",([GC_KISALAS:30]),GENDER_FEMALE);
    AddId("kisala");
    SetShort("nika la banquera");
    SetLong("Nika es una medio elfa que lleva el control de las finanzas en "
            "el gremio. Es una Kisala de edad avanzada, y no muy simpática "
            "por lo que puedes ver. Aún así, seguro que es muy eficiente en "
            "su labor.\n");

    AddId(({"nika","Nika","medio-elfa","medio-elfa","banquera","Kisala",
            "kisala"}));

    InitChats(3,({
              "Nika repasa las cuentas.\n",
              "Nika dice: Si no fuera por mí, este banco se venía abajo.\n",
            "Nika te dice: ¿Deseas algo?\n"}));

}
