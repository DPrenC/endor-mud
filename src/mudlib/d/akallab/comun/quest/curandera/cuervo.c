/*
DESCRIPCION : un cuervo para el quest de la curandera
FICHERO     : /d/akallab/comun/quest/curandera/cuervo.c
MODIFICACION: 24-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <living.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Cuervo","cuervo",2,GENERO_NEUTRO);
    SetName("cuervo");
    SetShort("un cuervo negro");
    SetLong("Es un inquieto cuervo negro que no para de moverse.\n");
    SetWeight(2000);
    SetGoChance(40);
    SetIds(({"cuervo","cuervo negro","pajaro","pájaro"}));
    SetAds(({"negro"}));
}

public varargs void Die(mixed silent)
{
    object ob;
    ob=clone_object(QUEST+"curandera/pluma");
    ob->move(environment(TO));
    ::Die(silent);
}
